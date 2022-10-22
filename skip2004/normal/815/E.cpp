#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, ll> pr;
using std::cin;
using std::cout;
ll n, k;
inline ll ask(ll n, ll x) {
	static std::map<pr, ll> map;
	if(n + 1 >> 1 < x) return 0;
	if(map.count(pr(n, x))) return map[pr(n, x)];
	return map[pr(n, x)] = ask(n - 1 >> 1, x) + ask(n >> 1, x) + 1;
}
inline ll eql(ll n, ll x) {
	static std::map<pr, ll> map;
	if(n + 1 >> 1 < x) return 0;
	if(map.count(pr(n, x))) return map[pr(n, x)];
	return map[pr(n, x)] = eql(n - 1 >> 1, x) + eql(n >> 1, x) + (n + 1 >> 1 == x);
}
inline ll kth(ll n, ll k, ll x) {
	k -= n + 1 >> 1 == x;
	if(!k) return n + 1 >> 1;
	if(k <= eql(n - 1 >> 1, x)) return kth(n - 1 >> 1, k, x);
	return kth(n >> 1, k - eql(n - 1 >> 1, x), x) + (n + 1 >> 1);
}
int main() {
	cin >> n >> k;
	if(k == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if(k == 2) {
		cout << n << '\n';
		return 0;
	}
	n -= 2;
	k -= 2;
	ll l = 1, r = 1e18;
	for(;l + 1 != r;) {
		ll mid = l + r >> 1;
		if(ask(n, mid) >= k) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << kth(n, k - ask(n, l + 1), l) + 1 << '\n';
}