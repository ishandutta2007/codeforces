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

const ll MOD = 1E9 + 7;

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int main(){
	int x, y;
	scanf("%d%d", &x, &y);
	if (y % x){
		puts("0");
		return 0;
	}
	y /= x;

	vector<int> a;
	int t = y;
	for (int i = 2; i * i <= t; ++i){
		if (t % i)
			continue;
		a.emplace_back(i);
		for (; t % i == 0; t /= i);
	}
	if (t > 1)
		a.emplace_back(t);

	ll ans = 0;
	for (int i = (1 << a.size()) - 1; i >= 0; --i){
		int s = 1;
		for (int j = 0; j < a.size(); ++j)
			if (i >> j & 1)
				s *= a[j];
		ans += (__builtin_popcount(i) & 1 ? -1 : 1) * modExp(2, y / s - 1);
	}
	printf("%lld\n", (ans % MOD + MOD) % MOD);
	return 0;
}