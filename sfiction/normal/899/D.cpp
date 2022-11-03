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
	ll n;
	scanf("%lld", &n);
	ll t = 1;
	for (; n / t >= 10; t *= 10);
	if (t * 5 <= n)
		printf("%lld\n", min(t * 5 - 1, n - 5 * t + 1));
	else if (n < 10)
		printf("%lld\n", n * (n - 1) / 2);
	else{
		ll x = (n + 1) % t;
		ll d = (n + 1) / t;
		printf("%lld\n", d * (t / 2 * d + x) + max(0ll, x - t / 2) - d);
	}
	return 0;
}