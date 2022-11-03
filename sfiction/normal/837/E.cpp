#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

int main(){
	ll n, m;
	scanf("%lld%lld", &n, &m);

	vector<ll> lst[2];
	lst[0].push_back(1);
	lst[1].push_back(n);
	for (ll i = 2; i * i <= n; ++i){
		if (n % i)
			continue;
		lst[0].push_back(i);
		lst[1].push_back(n / i);
	}
	if (lst[0].back() == lst[1].back())
		lst[1].pop_back();
	lst[0].insert(lst[0].end(), lst[1].rbegin(), lst[1].rend());

	ll ans = 0;
	while (m > 0){
		ll k = 1, r = m;
		ll d = __gcd(n, m);
		for (auto &x: lst[0]){
			if (x == d || x % d)
				continue;

			ll t = m % x;
			if (t > 0 && t <= r){
				k = x;
				r = t;
			}
		}
		eput(n, m, k, r, d, ans);
		ans += r / d;
		m -= r;
	}
	printf("%lld\n", ans);

	return 0;
}