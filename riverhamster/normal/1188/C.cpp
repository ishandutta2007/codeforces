#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 1005, M = 100005, mod = 998244353;
int f[N][N], res[M]; //f[i][j] stands for subseq of [1, i] length n beauty x
int n, k, a[N];

int dp(int x){
	// printf("DP: beauty >= %d\n", x);
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=k; j+=8) f[i][j] = f[i][j+1] = f[i][j+2] = f[i][j+3] = f[i][j+4] = f[i][j+5] = f[i][j+6] = f[i][j+7] = 0;
	int l = 0;
	for(int i=1; i<=n; i++){
		while(a[l+1] <= a[i] - x) ++l;
		f[i][1] = i;
		for(int j=2; j<=k; j++)
			f[i][j] = (f[i-1][j] + f[l][j-1]) % mod;//, printf("f[%d][%d] = %d, l = %d\n", i, j, f[i][j], l);
	}
	return f[n][k];
}

int main(){
	// File("cf1188c");
	int ans = 0, maxn = 0, maxi;
	in(n); in(k);
	for(int i=1; i<=n; i++) in(a[i]), maxn = max(maxn, a[i]);
	sort(a+1, a+1+n);
	maxi = maxn / (k-1) + 1;
	for(int i=1; i<=maxi; i++){
		res[i] = dp(i);
		// if(res[i] > 0) printf("res[%d] = %d\n", i, res[i]);
	}
	for(int i=1; i<=maxi; i++)
		res[i] = (res[i] - res[i+1] + mod) % mod;//, printf("res %d = %d\n", i, res[i]);
	for(int i=1; i<=maxi; i++){
		// if(res[i] != 0) printf("res[%d] = %d\n", i, res[i]);
		ans = (ans + 1LL * res[i] * i % mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}