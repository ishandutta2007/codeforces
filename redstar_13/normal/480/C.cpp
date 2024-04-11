#include<bits/stdc++.h>

#define x first
#define y second
#define mod 1000000007

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 5100

int dp[NN][NN];

int add(int &u, int v) {
	u += v;
	if(u >= mod) u -= mod;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, a, b, k;
	gn(n, a); gn(b, k);
	
	for(int i=1; i<=n; i++) {
		dp[i][0] = dp[i-1][0];
		dp[i][0] += (i != b);
	}
	
	for(int j=1; j<=k; j++) for(int i=1; i<=n; i++){
		dp[i][j] = dp[i-1][j];
		if(i == b) continue;
		int d = abs(i - b) - 1;
		int L = i - d, R = i + d;
		L = max(1, L); R = min(n, R);
		add(dp[i][j], dp[R][j-1]);
		add(dp[i][j], mod - dp[L-1][j-1]);
		add(dp[i][j], mod - dp[i][j-1]);
		add(dp[i][j], dp[i-1][j-1]);
	}
	
	int ans = 0;
	add(ans, dp[a][k]);
	add(ans, mod - dp[a-1][k]);
	
	cout<<ans<<endl;
}