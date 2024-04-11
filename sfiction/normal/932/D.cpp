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

const int N = 4E5 + 10, D = 18;

int n, q;
int p[D][N], val[D][N];	// for tree
int pr[D][N];
ll sum[D][N];	// for required path

int main(){
	scanf("%d", &q);
	
	int n = 1, last = 0;
	for (int qi = 1; qi <= q; ++qi){
		int com;
		scanf("%d", &com);
		if (com == 1){
			int u, w;
			scanf("%d%d", &u, &w);
			u ^= last, w ^= last;
			++n;
			p[0][n] = u, val[0][n] = w;
			for (int d = 1; d < D; ++d){
				int du = p[d - 1][n];
				p[d][n] = p[d - 1][du];
				val[d][n] = max(val[d - 1][n], val[d - 1][du]);
			}

			for (int d = D - 1; d >= 0; --d)
				if (val[d][u] < val[0][n])
					u = p[d][u];
			pr[0][n] = u, sum[0][n] = val[0][n];
			for (int d = 1; d < D; ++d){
				int du = pr[d - 1][n];
				pr[d][n] = pr[d - 1][du];
				sum[d][n] = sum[d - 1][n] + sum[d - 1][du];
			}
		}
		else{
			int u;
			ll X;
			scanf("%d%lld", &u, &X);
			u ^= last, X ^= last;

			int ans = 0;
			for (int d = D - 1; d >= 0; --d)
				if (pr[d][u] != 0 && X >= sum[d][u]){
					X -= sum[d][u];
					u = pr[d][u];
					ans += 1 << d;
				}
			if (X >= sum[0][u])
				++ans;

			printf("%d\n", ans);
			last = ans;
		}
	}
	return 0;
}