#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f; 
}

const int N = 505, Q = 6e5 + 5;
int n, m, q, ans[Q];
char s[N][N];
struct Query { int sx, sy, ex, ey, id; };
bitset<N> f[N][N], g[N][N];

vector<Query> bin[N << 4];

void push(int u, int l, int r, Query x) {
	int mid = (l + r) >> 1;
	if(x.sx <= mid && x.ex >= mid) return bin[u].push_back(x), void();
	if(x.ex <= mid) push(u << 1, l, mid, x);
	else push(u << 1 | 1, mid + 1, r, x);
}

void solve(int u, int l, int r) {
	int mid = (l + r) >> 1;
	if(bin[u].size()) {
		for(int i = l; i <= r; i++)
			for(int j = 1; j <= m; j++)
				f[i][j].reset(), g[i][j].reset();
		for(int j = m; j >= 1; j--) 
			if(s[mid][j] != '#') f[mid][j].set(j), f[mid][j] |= f[mid][j + 1];
		for(int j = 1; j <= m; j++)
			if(s[mid][j] != '#') g[mid][j].set(j), g[mid][j] |= g[mid][j - 1];
		for(int i = mid - 1; i >= l; i--)
			for(int j = m; j >= 1; j--) {
				if(s[i][j] == '#') continue;
				f[i][j] = f[i + 1][j] | f[i][j + 1];
			}
		for(int i = mid + 1; i <= r; i++)
			for(int j = 1; j <= m; j++) {
				if(s[i][j] == '#') continue;
				g[i][j] = g[i - 1][j] | g[i][j - 1];
			}
//		for(int i = l; i <= r; i++)
//			for(int j = 1; j <= m; j++) {
//				printf("%d %d: ", i, j);
//				for(int k = 1; k <= m; k++) printf("%d", (int)f[i][j][k]); printf("\n");
//			}
		for(int i = 0; i < bin[u].size(); i++) {
			int sx = bin[u][i].sx, sy = bin[u][i].sy, ex = bin[u][i].ex, ey = bin[u][i].ey, id = bin[u][i].id;
			ans[id] = (f[sx][sy] & g[ex][ey]).count() != 0;
		}
	}
	if(l == r) return;
	solve(u << 1, l, mid), solve(u << 1 | 1, mid + 1, r);
}

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	q = get();
	for(int i = 1; i <= q; i++) {
		int sx = get(), sy = get(), ex = get(), ey = get();
		Query now = (Query){ sx, sy, ex, ey, i };
		push(1, 1, n, now);
	}
	solve(1, 1, n);
	for(int i = 1; i <= q; i++) printf(ans[i]? "Yes\n" : "No\n");
	return 0;
}