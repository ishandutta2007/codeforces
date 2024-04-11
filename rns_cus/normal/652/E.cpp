#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

#define N 1001001
#define M 1001001

using namespace std;

typedef pair <int, int> pii;

int n, m;
int color[M<<1];
int to[M << 1], nxt[M << 1];
int head[N];

int dtime, dt[N], low[N];
int S[N], top;
pii Bridge[M];
int ArtP[N];
int cA, cB;
int clr[N];
vector <int> Ebcc[N];
int cnt;

bool vis[M];

inline int EID(int e) { return e > m ? e - m : e; }

void Init() {
	cA = cB = cnt = 0;
	for (int i = 1; i <= n; i ++) head[i] = 0;
	for (int i = 1; i <= n; i ++) dt[i] = low[i] = 0;
	for (int i = 1; i <= m; i ++) vis[i] = 0;
}

void AddEdge(int s, int e, int c, int u) {
	to[u] = e;
	color[u] = c;
	nxt[u] = head[s], head[s] = u;
}

void DFS(int u) {
	dt[u] = low[u] = ++ dtime;
	S[++ top] = u;
	int sz = 0;
	bool Artic = 0;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (vis[EID(i)]) continue;
		vis[EID(i)] = 1;
		if (dt[v]) low[u] = min(low[u], dt[v]);
		else {
			DFS(v);
			low[u] = min(low[u], low[v]);

			Artic |= low[v] >= dt[u], sz ++;						//ArtPoint
			if (low[v] > dt[u]) Bridge[++ cB] = make_pair(u, v);	//Bridge
		}
	}

	if (dt[u] == 1) Artic = sz > 1;		//ArtPoint
	if (Artic) ArtP[++ cA] = u;			//ArtPoint

	if (low[u] == dt[u]) {				//EBCC
		Ebcc[++ cnt].clear();
		int x;
		do {
			x = S[top --];
			Ebcc[cnt].push_back(x);
			clr[x] = cnt;
		} while (x != u);
	}
}

void Tarjan() {
	for (int i = 1; i <= n; i ++) if (!dt[i]) {
		dtime = top = 0;
		DFS(i);
	}
}

int good[M];
vector<int> v[M], w[M];
void solve() {
    for (int x = 1; x <= n; x++) {
        for (int y, c, i = head[x]; i; i = nxt[i]) {
            y = to[i];
            c = color[i];
            if (clr[x] == clr[y]) {
                good[clr[x]] |= c;
            } else {
                //printf("%d %d; %d\n", clr[x], clr[y], c);
                v[clr[x]].push_back(clr[y]), w[clr[x]].push_back(c);
                v[clr[y]].push_back(clr[x]), w[clr[y]].push_back(c);
            }
        }
    }
}

int q[M], st, en;
int flag[M];

void last() {
    int a, b;
    scanf("%d %d", &a, &b);
    a = clr[a], b = clr[b];
    st = 0;
    en = 1;
    flag[a] = 1;
    q[en] = a;
    //printf("a = %d, b = %d\n", a, b);
    while (st < en) {
        int x = q[++st];
        for (int y, i = 0; i < v[x].size(); i++) {
            y = v[x][i];
            if (flag[y]) {
                continue;
            }
            q[++en] = y;
            flag[y] = 1;
            good[y] |= good[x];
            good[y] |= w[x][i];
        }
    }
    //printf("en = %d\n", en);
    puts(flag[b] && good[b] ? "YES" : "NO");
}

int main() {
    //freopen("E2.in", "r", stdin);
	scanf("%d %d", &n, &m) > 0;
		Init();
		for (int i = 1; i <= m; i ++) {
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			AddEdge(x, y, c, i);
			AddEdge(y, x, c, i + m);
		}

		Tarjan();
		for (int i = 1; i <= n; i++) {
            //printf("clr[%d] = %d\n", i, clr[i]);
		}
		for (int i = 1; i <= cnt; i++) {
            //printf("good[%d] = %d\n", i, good[i]);
		}
		solve();
		last();
		/*printf("ArtPoints are: %d\n", cA);
		sort(ArtP + 1, ArtP + cA + 1);
		for (int i = 1; i <= cA; i ++) printf("%d ", ArtP[i]); puts("\n");
		printf("Bridges are: %d\n", cB);
		for (int i = 1; i <= cB; i ++) printf("{%d,%d}\n", Bridge[i].first, Bridge[i].second); puts("\n");
		printf("BCC count: %d\n", cnt);
		for (int i = 1; i <= cnt; i ++) {
			for (int j = 0; j < Ebcc[i].size(); j ++) printf("%d ", Ebcc[i][j]); puts("");
		}
		puts("");*/
    return 0;
}