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

const int N = 2E2 + 10;

int a[N][N];

void output(int n){
	printf("%d\n", n);
	for (int i = 0; i <= n; ++i)
		printf("%d%c", a[n][i], "\n "[i < n]);
}

int main(){
	int n;
	scanf("%d", &n);
	a[0][0] = 1;
	a[1][0] = 0, a[1][1] = 1;
	for (int i = 2; i <= n; ++i){
		for (int j = 0; j < n; ++j)
			a[i][j + 1] = a[i - 1][j];
		for (int j = 0; j < n - 1; ++j)
			a[i][j] = a[i][j] + a[i - 2][j] & 1;
	}
	output(n);
	output(n - 1);
	return 0;
}