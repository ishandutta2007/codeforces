#include<bits/stdc++.h>
#define int long long
#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, k, s[N], ans;
struct Node { int l, r; } seg[N];
vector<Node> pre[N], suf[N];

int tag[N << 2], cnt[N << 2][2];

void pushup(int u) { cnt[u][0] = cnt[lc][0] + cnt[rc][0], cnt[u][1] = cnt[lc][1] + cnt[rc][1]; }
void pusht(int u) { tag[u] ^= 1, swap(cnt[u][0], cnt[u][1]); }
void pushdown(int u) { if(tag[u]) pusht(lc), pusht(rc), tag[u] = 0; }

void build(int u, int l, int r) {
	if(l == r) return cnt[u][0] = 1, void();
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return pusht(u);
	pushdown(u);
	if(b <= mid) update(lc, l, mid, a, b);
	else if(a > mid) update(rc, mid + 1, r, a, b);
	else update(lc, l, mid, a, mid), update(rc, mid + 1, r, mid + 1, b);
	pushup(u);
}

int query(int u, int l, int r, int a, int b) {
	if(a > b) return 0;
	if(a == l && r == b) return cnt[u][1];
	pushdown(u);
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return query(lc, l, mid, a, mid) + query(rc, mid + 1, r, mid + 1, b);
}

main() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) s[i] = get();
	sort(s + 1, s + 1 + n);
	for(int i = 1, l, r; i <= k; i++) {
		l = get(), r = get();
		l = lower_bound(s + 1, s + 1 + n, l) - s, r = upper_bound(s + 1, s + 1 + n, r) - s - 1;
		if(l > r) continue;
		pre[r].push_back((Node){ l, r }), suf[l].push_back((Node){ l, r });
	}
	build(1, 1, n);
	for(int i = 1; i <= n; i++) {
		for(auto v : suf[i]) update(1, 1, n, i, v.r);
		int d = query(1, 1, n, 1, i - 1) + query(1, 1, n, i + 1, n);
		ans += d * (d - 1) / 2;
		update(1, 1, n, i, i);
		for(auto v : pre[i]) update(1, 1, n, v.l, i);
	}
	ans = n * (n - 1) * (n - 2) / 6 - ans;
	cout << ans; 
	return 0;
}