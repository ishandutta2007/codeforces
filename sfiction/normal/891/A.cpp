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

const int N = 2E3 + 10;

int n;
int a[N];

int main(){
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		cnt += a[i] == 1;
	}
	if (cnt){
		printf("%d\n", n - cnt);
		return 0;
	}
	int ans = n + 1;
	for (int i = 1; i <= n; ++i){
		int d = a[i], j = i + 1;
		for (; j <= n && d > 1; ++j)
			d = __gcd(d, a[j]);
		if (d == 1)
			mini(ans, j - i - 1);
	}
	printf("%d\n", ans > n ? -1 : ans + n - 1);
	return 0;
}