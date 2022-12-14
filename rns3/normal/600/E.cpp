#include <map>
#include <cstdio>

using namespace std;

#define N 100005

typedef __int64 LL;

int n, c[N];
int head[N], to[N << 1], nxt[N << 1];

map <int, int> cnt[N];
map <int, int> :: iterator it;
int ps[N], mx[N];
LL sum[N], rlt[N];

void AddEdge(int a, int b, int i) {
	to[i] = b;
	nxt[i] = head[a];
	head[a] = i;
}

int Merge(int a, int b) {
	if (cnt[a].size() < cnt[b].size()) swap(a, b);
	for (it = cnt[b].begin(); it != cnt[b].end(); it ++) {
		int color = it -> first;
		int tmp = cnt[a][color] + it -> second;
		cnt[a][color] = tmp;
		if (tmp > mx[a]) mx[a] = tmp, sum[a] = color;
		else if (tmp == mx[a]) sum[a] += color;
	}
	return a;
}

void DFS(int u, int pr = 0) {
	ps[u] = u;
	mx[u] = 1;
	sum[u] = c[u];
	cnt[u][c[u]] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != pr) {
			DFS(v, u);
			ps[u] = Merge(ps[u], ps[v]);
		}
	}
	rlt[u] = sum[ps[u]];
}

main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", c + i);
	for (int i = 1; i < n; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		AddEdge(a, b, i);
		AddEdge(b, a, i + n - 1);
	}
	DFS(1);
	for (int i = 1; i <= n; i ++) printf("%I64d ", rlt[i]);
}