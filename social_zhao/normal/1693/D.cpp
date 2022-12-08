#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, p[N], lim[N];
vector<int> lft[N], rht[N];

void qmax(int &x, int y) { x = max(x, y); }

namespace BIT {
	int mx[N];
	int lowbit(int x) { return x & -x; }
	void clear() { memset(mx, 0, sizeof(mx)); }
	void add(int x, int v) { while(x <= n) mx[x] = max(mx[x], v), x += lowbit(x); }
	int ask(int x) { int r(0); while(x) r = max(r, mx[x]), x -= lowbit(x); return r; }
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) p[i] = get();
	BIT::clear();
	for(int i = 1; i <= n; i++) {
		int pre = BIT::ask(p[i]);
		if(pre) rht[pre].emplace_back(i);
		BIT::add(p[i], i);
	}
	BIT::clear();
	for(int i = n; i >= 1; i--) {
		int suf = n - BIT::ask(n - p[i] + 1) + 1;
		if(suf <= n) lft[suf].emplace_back(i);
		BIT::add(n - p[i] + 1, n - i + 1);
	}
	BIT::clear();
	for(int i = 1; i <= n; i++) {
		for(auto v : rht[i]) qmax(lim[v], BIT::ask(n - p[v] + 1));
		for(auto v : lft[i]) BIT::add(n - p[v] + 1, v);
	}
	for(int i = 1; i <= n; i++) lft[i].clear(), rht[i].clear();
	
	BIT::clear();
	for(int i = 1; i <= n; i++) {
		int pre = BIT::ask(n - p[i] + 1);
		if(pre) rht[pre].emplace_back(i);
		BIT::add(n - p[i] + 1, i);
	}
	BIT::clear();
	for(int i = n; i >= 1; i--) {
		int suf = n - BIT::ask(p[i]) + 1;
		if(suf <= n) lft[suf].emplace_back(i);
		BIT::add(p[i], n - i + 1);
	}
	BIT::clear();
	for(int i = 1; i <= n; i++) {
		for(auto v : rht[i]) qmax(lim[v], BIT::ask(p[v]));
		for(auto v : lft[i]) BIT::add(p[v], v);
	}
	
	for(int i = 1; i <= n; i++) lim[i] = max(lim[i], lim[i - 1]);
	long long ans = 0;
	for(int i = 1; i <= n; i++) ans += i - lim[i];
	cout << ans << endl;
	return 0;
}