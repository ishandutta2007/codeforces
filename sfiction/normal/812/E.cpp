#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

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

const int MAXN = 1E5 + 10;

int val[MAXN], dep[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", val + i);
	dep[1] = 0;
	int mdep = 0;
	for (int p, i = 2; i <= n; ++i){
		scanf("%d", &p);
		maxi(mdep, dep[i] = dep[p] + 1);
	}

	map<int, int> lst[2];
	int d0 = mdep & 1, s = 0;
	int cnt[2] = {0, 0};
	for (int i = 1; i <= n; ++i){
		++lst[dep[i] &= 1][val[i]];
		++cnt[dep[i]];
		if (dep[i] == d0)
			s ^= val[i];
	}

	ll ans = 0;
	if (s == 0)
		ans += n * (n - 1ll) / 2 - 1ll * cnt[0] * cnt[1];
	for (int i = 1; i <= n; ++i)
		if (dep[i] == d0 && lst[!d0].count(val[i] ^ s))
			ans += lst[!d0][val[i] ^ s];
	printf("%lld\n", ans);
	return 0;
}