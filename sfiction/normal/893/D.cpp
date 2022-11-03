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

const int N = 1E5 + 10;

int a[N], b[N];

int main(){
	int n, D;
	scanf("%d%d", &n, &D);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	partial_sum(a + 1, a + n + 1, a + 1);
	b[n] = a[n];
	for (int i = n - 1; i >= 1; --i)
		b[i] = max(b[i + 1], a[i]);

	ll up = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (up + a[i] > D){
			puts("-1");
			return 0;
		}
		else if (a[i] == a[i - 1] && up + a[i] < 0){
			if (b[i] - a[i] > D){
				puts("-1");
				return 0;
			}
			up = D - b[i];
			++ans;
		}
	printf("%d\n", ans);
	return 0;
}