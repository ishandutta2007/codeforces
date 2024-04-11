#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 201000;
using std::cin;
using std::cout;
struct pr {
	ll a, b;
	inline void mg(const pr& x) { a ^= x.a, b ^= x.b; }
	inline int operator < (const pr & x) const {
		return a != x.a ? a < x.a : b < x.b;
	}
} a[maxn], num[maxn], pre[maxn], suf[maxn], all;
std::mt19937_64 rd(time(0) + (size_t) new char);
std::map<pr, pr> map;
int n, m;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> m >> n;
	for(int i = 1, l, r;i <= m;++i) {
		cin >> l >> r;
		num[i].a = rd();
		num[i].b = rd();
		a[l].mg(num[i]);
		a[r + 1].mg(num[i]);
		all.mg(num[i]);
		pre[r].mg(num[i]);
		suf[l].mg(num[i]);
	}
	ll ans = 0;
	for(int i = 1, len = 0;i <= n;++i) {
		a[i].mg(a[i - 1]);
		if(a[i].a == 0 && a[i].b == 0) {
			++ len;
		}
		if(a[i].a || a[i].b || i == n) {
			for(int x = 1;x <= len;++x) ans -= (ll) x * (len - x + 1);
			len = 0;
		}
	}
	for(int i = 1;i <= n;++i) a[i].mg(a[i - 1]);
	for(int i = 1;i <= n;++i) pre[i].mg(pre[i - 1]);
	for(int i = n;i >= 1;--i) suf[i].mg(suf[i + 1]);
	for(int j = 1;j <= n;++j) {
		auto __ = a[j - 1]; __.mg(pre[j - 1]);
		pr&now = map[__]; now.a += 1, now.b += j;
		auto x = a[j]; x.mg(suf[j + 1]); x.mg(all);
		pr&v = map[x]; ans += (j + 1) * v.a - v.b;
	}
	cout << ans <<'\n';
}