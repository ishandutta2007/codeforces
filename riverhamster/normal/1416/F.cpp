#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
const int Node = 100005, Edge = 2 * (Node * 2 + Node * 2);

struct MinCostMaxFlow{
	int to[Edge], nt[Edge], hd[Node], f[Edge], w[Edge], h[Node], cur[Node], ec = 0;
	int S, T;
	int n;
	void init(int nc){ec = 0; n = nc; fill(hd, hd + nc, -1);}
	MinCostMaxFlow(){init(Node);}
	int link(int x, int y, int flow, int cost){
		to[ec] = y; nt[ec] = hd[x]; hd[x] = ec; f[ec] = flow; w[ec] = cost; ++ec;
		to[ec] = x; nt[ec] = hd[y]; hd[y] = ec; f[ec] = 0; w[ec] = -cost; ++ec;
		return ec - 1;
	}

	bool spfa(){
		deque<int> q;
		fill(h, h + n, 0x3f3f3f3f);
		h[S] = 0; q.push_back(S);
		while(!q.empty()){
			int x = q.front(); q.pop_front();
			for(int i=hd[x]; i!=-1; i=nt[i]){
				if(f[i] && h[to[i]] > h[x] + w[i]){
//				  printf("f %d\n",f[i]);
					h[to[i]] = h[x] + w[i];
					if(!q.empty() && h[to[i]] <= h[q.front()]) q.push_front(to[i]);
					else q.push_back(to[i]);
				}
			}
		}
		return h[T] != 0x3f3f3f3f;
	}
	bool vis[Node];
	int dfs(int x, int flow){
//	  printf("dfs %d flow %d\n",x,flow);
		if(x == T || !flow) return flow;
		int res = 0;
		vis[x] = true;
		for(int i=hd[x]; i!=-1; i=nt[i]){
			if(vis[to[i]] || h[to[i]] != h[x] + w[i] || !f[i]) continue;
			int aug = min(flow, f[i]);
			if((aug = min(aug, dfs(to[i], aug)))){
				f[i] -= aug; f[i^1] += aug;
				flow -= aug; res += aug;
			}
			if(!flow) break;
		}
		vis[x] = false;
		if(!res) h[x] = 0x3f3f3f3f;
		return res;
	}
	int mincost() {
	  int res = 0;
	  while (spfa()) {
	    if (h[T] >= 0) break;
	    int fl = dfs(S, 0x3f3f3f3f);
	    res += fl * h[T];
	    for (int i = 1; i <= 10000000; ++i);
    }
    return res;
  }
}G;

const int N = 100005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dir[] = "DRUL";
int a[N], d[N], eid[N][4];
bool type[N];
bool cover[N];
char res[N];
int val[N];
int n, m;

int id(int x, int y) {
  return x * m + y;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    G.init(n * m + 2);
    for (int i = 0, li = n * m; i < li; ++i)
      for (int d = 0; d < 4; ++d)
        eid[i][d] = -1;
    G.S = n * m; G.T = n * m + 1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int x = id(i, j);
        scanf("%d", &a[x]);
        type[x] = (i ^ j) & 1;
      }
    fill(cover, cover + n * m, true);
    int require = n * m;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int x = id(i, j);
        for (int d = 0; d < 4; ++d) {
          int ni = i + dx[d], nj = j + dy[d];
          if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
          int y = id(ni, nj);
          if (a[x] > a[y]) {
            cover[x] = false;
            --require;
            break;
          }
        }
      }
    for (int i = 0; i < n * m; ++i)
      if (type[i]) G.link(i, G.T, 1, -int(cover[i]));
      else G.link(G.S, i, 1, -int(cover[i]));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        for (int d = 0; d < 4; ++d) {
          int ni = i + dx[d], nj = j + dy[d];
          if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
          int x = id(i, j), y = id(ni, nj);
          if (a[x] == a[y] && !type[x])
            eid[x][d] = G.link(x, y, 1, 0);
        }
    int c = -G.mincost();
    if (c < require) {
      puts("NO");
      continue;
    }
    else {
      puts("YES");
      fill(res, res + n * m, 0);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
          int x = id(i, j);
          for (int d = 0; d < 4; ++d)
            if (eid[x][d] != -1 && G.f[eid[x][d]] == 1) {
              int y = id(i + dx[d], j + dy[d]);
              res[x] = dir[d]; res[y] = dir[d ^ 2];
              val[x] = 1; val[y] = a[x] - 1;
            }
        }
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
          int x = id(i, j);
          if (!res[x])
            for (int d = 0; d < 4; ++d) {
              int ni = i + dx[d], nj = j + dy[d];
              if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                int y = id(ni, nj);
                if (a[x] > a[y])
                  res[x] = dir[d], val[x] = a[x] - a[y];
              }
            }
        }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
          printf("%d ", val[id(i, j)]);
        putchar('\n');
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
          putchar(res[id(i, j)]), putchar(' ');
        putchar('\n');
      }
    }
  }
  return 0;
}