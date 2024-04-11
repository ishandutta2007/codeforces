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

const int N = 2E5 + 10;

int n;
int a[N], b[N];
vector<pii> lst;

int h[N];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", a + i, b + i), lst.emplace_back(a[i] + b[i], i);
	sort(all(lst));

	set<int> c;
	ll ans = 0;
	for (int i = 0; i < n; ++i){
		int u = lst[i].nd, l, r;
		if (i == 0){
			h[u] = a[u] + b[u], ans += b[u];
			c.emplace(u);
			continue;
		}

		auto p = c.lower_bound(u);
		l = c.begin() == p ? 0 : *prev(p);
		r = c.end() == p ? n + 1 : *p;

		int t = a[u] + b[u], t2 = a[u];
		if (l > 0)
			t = min(t, h[l] + (u - l)), t2 = max(t2, h[l] - (u - l));
		if (r <= n)
			t = min(t, h[r] + (r - u)), t2 = max(t2, h[r] - (r - u));
		if (t < t2){
			puts("-1");
			return 0;
		}
		h[u] = t, ans += t - a[u];
		c.emplace(u);
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", h[i], "\n "[i < n]);
	return 0;
}