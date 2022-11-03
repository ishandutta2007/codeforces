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

const int MAXN = 2E5 + 10;

ll a[MAXN];

int main(){
	int n;
	ll k;
	scanf("%d%lld", &n, &k);
	int m = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", a + m);
		if (m || a[m])
			++m;
	}
	n = m;

	if (*max_element(a, a + m) >= k){
		puts("0");
		return 0;
	}
	if (n == 2){
		printf("%lld\n", (k - a[1] + a[0] - 1) / a[0]);
		return 0;
	}
	if (n == 3){
		ll low = 0, high = 1ll << 31, mid;
		while (low < high){
			mid = low + (high - low >> 1);
			ll t = k - a[2] - a[1] * mid;
			eput(low, high, mid, t);
			if (t > 0){
				ll t0 = mid * (mid + 1) / 2;
				eput(t0, t / t0);
				if (t / t0 >= a[0]){
					t -= t0 * a[0];
				}
				else
					t = 0;
			}
			eput(t);
			if (t > 0)
				low = mid + 1;
			else
				high = mid;
		}
		printf("%lld\n", low);
		return 0;
	}

	// at least 4 ??
	int ans = 0;
	bool flag = false;
	do{
		++ans;
		for (int j = 1; j < n; ++j)
			flag |= (a[j] += a[j - 1]) >= k;
	}
	while (!flag);
	printf("%d\n", ans);

	return 0;
}