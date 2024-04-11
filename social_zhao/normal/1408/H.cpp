#include<bits/stdc++.h>
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

const int N = 5e5 + 5, inf = 0x3f3f3f3f;
int n, cnt0, lim, a[N], pre[N], suf[N], lst0;
vector<int> bin[N];

int mn[N << 2], tag[N << 2], ber;

void pushup(int u) { mn[u] = min(mn[lc], mn[rc]); }
void pusht(int u, int v) { mn[u] += v, tag[u] += v; }
void pushdown(int u) { pusht(lc, tag[u]), pusht(rc, tag[u]), tag[u] = 0; }

void build(int u, int l, int r) {
	tag[u] = 0;
	if(l == r) {
		if(a[l] == 0 && l != n + 1) ++ber, mn[u] = ber;
		else mn[u] = ber;
		return;
	} 
	build(rc, mid + 1, r), build(lc, l, mid), pushup(u);
}

void update(int u, int l, int r, int a, int b, int v) {
	if(a > b) return;
	if(a == l && r == b) return pusht(u, v);
	pushdown(u);
	if(b <= mid) update(lc, l, mid, a, b, v);
	else if(a > mid) update(rc, mid + 1, r, a, b, v);
	else update(lc, l, mid, a, mid, v), update(rc, mid + 1, r, mid + 1, b, v);
	pushup(u);
}

void solve() {
	n = get(), cnt0 = 0, ber = 0, lst0 = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), cnt0 += a[i] == 0;
	for(int i = 1; i <= n; i++) if(!a[i]) lst0 = max(lst0, i);
	a[n + 1] = 0, a[0] = -1;
	
	if(cnt0 <= 1) return printf("0\n"), void();
	
	int now = 0;
	for(int i = 1; i <= n; i++) {
		now += a[i] == 0;
		if(now == cnt0 / 2) { lim = i; break; }
	}
	
	build(1, lim + 1, n + 1);
	
	for(int i = 1; i <= n; i++) pre[i] = 0, suf[i] = n + 1, bin[i].clear();
	for(int i = 1; i <= lim; i++) pre[a[i]] = max(pre[a[i]], i);
	for(int i = lim + 1; i <= n; i++) suf[a[i]] = min(suf[a[i]], i);
	
	int cntL = 0;
	for(int i = 1; i <= n; i++) {
		if(pre[i]) ++cntL, bin[pre[i]].push_back(suf[i]);
		else update(1, lim + 1, n + 1, suf[i] + 1, n + 1, 1);
	}
	
	int ans = cnt0 / 2, now0 = 0;
	for(int i = 0; i <= lim; i++) {
		for(auto v : bin[i]) 
			update(1, lim + 1, n + 1, v + 1, n + 1, 1), cntL--;
		if(a[i] == 0) ++now0;
		ans = min(ans, now0 + mn[1] + cntL);
	}
	
	cout << ans << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
12
0 1 2 3 0 0 0 0 4 5 6 0
1
5
0 1 0 0 2
*/