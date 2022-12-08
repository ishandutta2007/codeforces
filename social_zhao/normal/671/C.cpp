#include<bits/stdc++.h>
#define int long long
#define lc (u << 1)
#define rc (u << 1 | 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, M = N << 4;
int n, a[N], sum[M], mx[M], mn[M], tag[M], lst, ans, L[M], R[M];
vector<int> pos[N];

void pushup(int u) {
	sum[u] = sum[lc] + sum[rc], mn[u] = min(mn[lc], mn[rc]), mx[u] = max(mx[lc], mx[rc]);
}

void pusht(int u, int v) {
	mx[u] = mn[u] = tag[u] = v, sum[u] = (R[u] - L[u] + 1) * v;
}

void pushdown(int u) {
	if(tag[u]) pusht(lc, tag[u]), pusht(rc, tag[u]), tag[u] = 0;
}

void build(int u, int l, int r) {
	L[u] = l, R[u] = r;
	if(l == r) return (void)(sum[u] = mx[u] = mn[u] = l);
	int mid = (l + r) >> 1;
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int a, int b, int v) {
	if(a > b ||  l > b || r < a || mn[u] >= v) return;
	if(a <= l && r <= b && mx[u] <= v) return (void)(pusht(u, v));
	if(l == r) return (void)(sum[u] = mx[u] = mn[u] = v);
	int mid = (l + r) >> 1;
	pushdown(u);
	update(lc, l, mid, a, b, v), update(rc, mid + 1, r, a, b, v);
	pushup(u);
}

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		a[i] = get();
		for(int j = 1; j * j <= a[i]; j++) {
			if(a[i] % j) continue;
			pos[j].push_back(i);
			if(j * j != a[i]) pos[a[i] / j].push_back(i);
		}
	}
	build(1, 1, n);
	lst = (n + 1) * n - sum[1];
	for(int i = 200000; i >= 1; i--) {
		int len = pos[i].size();
		if(len < 2) continue;
		update(1, 1, n, pos[i][1] + 1, n, n + 1);
		update(1, 1, n, 1, pos[i][0], pos[i][len - 2]);
		update(1, 1, n, pos[i][0] + 1, pos[i][1], pos[i][len - 1]);
		ans += (lst - ((n + 1) * n - sum[1])) * i;
		lst = (n + 1) * n - sum[1];
	}
	printf("%lld\n", ans);
	return 0;
}