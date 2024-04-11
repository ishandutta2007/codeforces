#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 4E5 + 10;

typedef long long ll;

int n, m;
vector<int> E[MAXN];

int tot;
int color[MAXN], colorSeg[MAXN];
int left[MAXN], right[MAXN];

int L, R;
ll C;
ll s[MAXN << 2], lazy[MAXN << 2];

void DFS(int u, int pre){
	colorSeg[tot] = color[u];
	left[u] = tot++;
	for (int i = 0; i < E[u].size(); ++i)
		if (E[u][i] != pre)
			DFS(E[u][i], u);
	right[u] = tot;
}

inline void pushDown(int u){
	s[u << 1] = lazy[u << 1] = s[u << 1 | 1] = lazy[u << 1 | 1] = lazy[u];
	lazy[u] = 0;
}

void build(int u, int l, int r){
	if (l + 1 == r){
		s[u] = 1ll << colorSeg[l];
		return;
	}
	int m = l + r >> 1;
	build(u << 1, l, m);
	build(u << 1 | 1, m, r);
	s[u] = s[u << 1] | s[u << 1 | 1];
}

void update(int u, int l, int r){
	if (L <= l && r <= R){
		s[u] = lazy[u] = C;
		return;
	}
	if (lazy[u])
		pushDown(u);
	int m = l + r >> 1;
	if (L < m)
		update(u << 1, l, m);
	if (m < R)
		update(u << 1 | 1, m, r);
	s[u] = s[u << 1] | s[u << 1 | 1];
}

void query(int u, int l, int r){
	if (L <= l && r <= R){
		C |= s[u];
		return;
	}
	if (lazy[u])
		pushDown(u);
	int m = l + r >> 1;
	if (L < m)
		query(u << 1, l, m);
	if (m < R)
		query(u << 1 | 1, m, r);
	s[u] = s[u << 1] | s[u << 1 | 1];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &color[i]), --color[i];
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	build(1, 0, n);
	for (int com, u, c, i = 0; i < m; ++i){
		scanf("%d%d", &com, &u);
		if (com == 1){
			scanf("%d", &c);
			L = left[u], R = right[u], C = 1ll << c - 1, update(1, 0, n);
		}
		else{
			L = left[u], R = right[u], C = 0, query(1, 0, n);
			printf("%d\n", (int)__builtin_popcountll(C));
		}
	}
	return 0;
}