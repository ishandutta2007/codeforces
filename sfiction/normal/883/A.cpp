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

const int MAXN = 1E5 + 10;

int m;
ll n, A, D;
ll a[MAXN];

int main(){
	scanf("%lld%d%lld%lld", &n, &m, &A, &D);
	for (int i = 1; i <= m; ++i)
		scanf("%lld", a + i);
	sort(a + 1, a + m + 1);
	a[0] = 0, a[m + 1] = 1ll << 60;
	
	typedef pair<ll, int> pli;
	vector<pli> b;
	for (int i = 0; i <= m; ++i){
		ll l = max(1ll, min(n + 1, (a[i] + A - 1) / A)), r = max(1ll, min(n + 1, (a[i + 1] + A - 1) / A));
		b.emplace_back(a[i], 1);
		if (l != r)
			b.emplace_back(l * A, r - l);
	}


	ll ans = 0;
	for (int i = 1; i < b.size(); ){
		if (b[i].nd == 0){
			++i;
			continue;
		}

		ll t0 = b[i].st;
		if (t0 + D < t0 + A * (b[i].nd - 1)){
			ll t = D / A + 1;
			ans += b[i].nd / t;
			b[i].st += b[i].nd / t * t * A;
			b[i].nd %= t;
			if (b[i].nd == 0){
				--ans;
				b[i].st -= t * A;
				b[i].nd += t;
			}
		}
		else{
			int j = i;
			for (; j < b.size() && t0 + D >= b[j].st + A * (b[j].nd - 1); ++j);
			++ans;
			if (j < b.size()){
				ll tr = t0 + D - b[j].st;
				if (tr >= 0){
					tr = tr / A + 1;
					b[j].st += tr * A;
					b[j].nd -= tr;					
				}
			}
			i = j;
		}
	}
	printf("%lld\n", ans);
	return 0;
}