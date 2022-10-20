#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 105;
const ll mod = 1000000007;
ll ans[N][N], now[N][N], tmp[N][N];
ll n, m;

void mul(ll a[N][N], ll b[N][N]){
	memset(tmp, 0, sizeof tmp);
	for(int i=1; i<=m; i++)
		for(int j=1; j<=m; j++)
			for(int k=1; k<=m; k++)
				tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
	memcpy(a, tmp, sizeof tmp);
}

int main(){
	// freopen("d.in", "r", stdin);
	// freopen("d.out", "w", stdout);
	in(n); in(m);
	if(n < m){
		puts("1");
		return 0;
	}
	n -= m - 1;
	for(int i=2; i<=m; i++)
		now[i][i-1] = 1;
	now[1][1] = 1; now[1][m] = 1;
	for(int i=1; i<=m; i++) ans[i][i] = 1;
	// printf("n = %d\n", n);
	while(n){
		if(n & 1) mul(ans, now);
		mul(now, now);
		n >>= 1;
	}
	ll res = 0;
	for(int i=1; i<=m; i++) res = (res + ans[1][i]) % mod;//, printf("ans[1][%d] = %lld\n", i, ans[1][i]);
	printf("%lld\n", res);
	return 0;
}