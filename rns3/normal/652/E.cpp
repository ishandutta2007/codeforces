#include <bits/stdc++.h>

using namespace std;

#define N 300005

int n, m;
int head[N], to[N << 1], nxt[N << 1], bf[N << 1];

int dtime, dt[N], low[N];
int S[N], top;

int col[N], C;
bool vis[N << 1];

inline int EID(int e) { return e > m ? e - m : e; }

void AddEdge(int a, int b, int c, int i) {
	to[i] = b;
	bf[i] = c;
	nxt[i] = head[a];
	head[a] = i;
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
		}
	}

	if (low[u] == dt[u]) {				//EBCC
    C ++;
		int x;
		do {
			x = S[top --];
			col[x] = C;
		} while (x != u);
	}
}

void Tarjan() {
	for (int i = 1; i <= n; i ++) if (!dt[i]) {
		dtime = top = 0;
		DFS(i);
	}
}

bool chk[N];
bool VIS[N];

vector <int> V[N], U[N];

void DFS_1(int x, int y, bool bf) {
  VIS[x] = 1;
  bf |= chk[x];
  if (x == y) {
    puts(bf ? "YES" : "NO");
    exit(0);
  }
  for (int i = 0; i < V[x].size(); i ++) {
    int xx = V[x][i];
    if (VIS[xx]) continue;
    DFS_1(xx, y, bf | U[x][i]);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i ++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    AddEdge(a, b, c, i);
    AddEdge(b, a, c, i + m);
  }

  int a, b;
  scanf("%d %d", &a, &b);

  Tarjan();
  for (int i = 1; i <= n; i ++) {
    for (int k = head[i]; k; k = nxt[k]) {
      int j = to[k];
      if (col[i] == col[j]) chk[col[i]] |= bf[k];
      else {
        V[col[i]].push_back(col[j]);
        U[col[i]].push_back(bf[k]);
        V[col[j]].push_back(col[i]);
        U[col[j]].push_back(bf[k]);
      }
    }
  }
  if (col[a] == col[b]) {
    if (chk[col[a]]) puts("YES");
    else puts("NO");
  } else {
    DFS_1(col[a], col[b], 0);
  }
}