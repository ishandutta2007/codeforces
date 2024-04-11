#include <bits/stdc++.h>

#define eps 1e-7
#define sq(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define rep(i, a, b) for (i=(a); i<(b); i++)
#define bpt(x) __builtin_popcount(x)
#define isset(x, y) ((x)&(1<<(y)))
#define pb push_back
#define beyond(u, v) (u<0 || v<0 || u>=N || v>=M)
#define x first
#define y second

#define FILEIO(name) \
	freopen(name".in", "r", stdin); \
	freopen(name".out", "w", stdout);

using namespace std;
typedef long long INT;
typedef long double DO;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

int main() {
	INT n;
	scanf("%I64d", &n);
	INT a=2, k=1, x;
	for (k=1; k<=n; k++) {
		x=k*(k+1)*(k+1)-a/k;
		printf("%I64d\n", x);
		a=(INT)(sqrt((DO)a+(DO)x*k)+eps);
	}

	return 0;
}