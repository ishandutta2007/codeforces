#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define mod 998244353

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 200010
#define MM 3100

INT dp[MM][MM];
int a[NN];
int w[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) gn(w[i]);
	for(int i=1; i<=n; i++) gn(a[i]);
	
	INT tot_dis = 0, tot = 0, tot_like = 0;
	
	for(int i=1; i<=n; i++) {
		if(w[i]) tot_like += a[i];
		else tot_dis += a[i];
		tot += a[i];
	}
	
	dp[0][0] = 1;
	
	for(int i=1; i<=m; i++) {
		dp[i][0] = dp[i-1][0] * (tot_like + i - 1) % mod * power(tot+i-1, mod-2, mod) % mod;
		for(int j=1; j<=i; j++) if(tot_dis >= j){
			INT x = 0, y = 0;
			x = dp[i-1][j-1] * power(tot + i + 1 - 2 * j, mod-2, mod) % mod *
				(tot_dis - j + 1) % mod;
			if(i != j) y = dp[i-1][j] * power(tot + i - 1 - 2 * j, mod-2, mod) % mod *
				(tot_like + i - 1 - j) % mod;
			dp[i][j] = (x + y) % mod;
		}
	}
	
	INT sum = 0;
	for(int j=0; j<=m; j++) sum += j * dp[m][j] % mod * power(tot_dis, mod-2, mod) % mod;
	sum %= mod;
	
	INT s = 0;
	
	for(int j=0; j<=m; j++) s += j * dp[m][m-j] % mod * power(tot_like, mod - 2, mod) % mod;
	
	for(int i=1; i<=n; i++) {
		if(w[i]) {
			INT x = s * a[i] % mod;
			x = (x + a[i]) % mod;
			printf("%I64d\n", x);
			continue;
		}
		INT x = sum * a[i] % mod;
		x = a[i] - x;
		x = (x % mod + mod) % mod;
		printf("%I64d\n", x);
	}
	return 0;
}