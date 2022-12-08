#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, q, a[N], pre[N], suf[N], pos[N], der[N], lst[N], ban[N], ans[N];

struct BIT {
	int sum[N];
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x <= n) sum[x] += v, x += lowbit(x); }
	int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
	int ask(int l, int r) { return ask(r) - ask(l - 1); }
} col, cov;

struct Ask { int l, r; };
vector<Ask> bin[N];

int main() {
	n = get();
	for(int i = 1; i <= 100000; i++) pos[i] = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), pre[i] = pos[a[i]], pos[a[i]] = i;
	for(int i = 1; i <= 100000; i++) pos[i] = n + 1;
	for(int i = n; i >= 1; i--) suf[i] = pos[a[i]], pos[a[i]] = i;
	for(int i = 1; i <= n; i++) {
		if(pre[pre[i]] && i - pre[i] != pre[i] - pre[pre[i]]) der[i] = lst[a[i]], lst[a[i]] = ban[i] = pre[pre[i]];
	}
	q = get();
	for(int i = 1, l, r; i <= q; i++) l = get(), r = get(), bin[r].push_back((Ask){ l, i });
	for(int i = 1; i <= n; i++) {
		col.add(i, 1); if(pre[i]) col.add(pre[i], -1);
		if(ban[i]) {
			cov.add(ban[i], 1);
			if(der[i]) cov.add(der[i], -1);
		}
		for(auto v : bin[i]) {
			int x = col.ask(v.l, i), y = cov.ask(v.l, i);
			if(x == y) ans[v.r] = x + 1;
			else ans[v.r] = x;
		}
	}
	for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}