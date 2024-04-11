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
	while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
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

vector<ll> gen(int n){
	vector<int> a(n);
	vector<ll> s(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i){
		ll s0 = 0, s1 = 1ll << 60;
		for (int j = 0; j < i - 1; ++j)
			s0 += a[j];
		for (int j = i - 1; j < n; ++j){
			s0 += a[j];
			mini(s1, s0);
			s0 -= a[j - i + 1];
		}
		s[i - 1] = s1;
	}
	return s;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<ll> a = gen(n), b = gen(m);

	ll X;
	scanf("%lld", &X);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = m - 1; j >= 0; --j)
			if (X / a[i] >= b[j]){
				maxi(ans, (i + 1ll) * (j + 1));
				break;
			}
	printf("%lld\n", ans);
	return 0;
}