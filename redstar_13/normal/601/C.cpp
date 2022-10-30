#include<bits/stdc++.h>

using namespace std;

typedef double DO;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

#define NN 111
#define MM 100010

int x[NN];
DO dp[NN][MM], sum[NN][MM];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, m;
	gn(n, m);
	
	int MA = n * m;
	int tot = 0;
	
	for(int i=1; i<=n; i++) {
		gn(x[i]);
		tot += x[i];
	}
	if(m == 1) return puts("1"), 0;
	
	dp[0][0] = 1.;
	for(int i=0; i<=MA; i++) sum[0][i] = 1.;
	
	for(int i=1; i<=n; i++) for(int j=1; j<=MA; j++) {
		int R = j - 1, L = max(0, j - m);
		if(L == 0) dp[i][j] = sum[i-1][R];
		else dp[i][j] = sum[i-1][R] - sum[i-1][L-1];
		
		if(j >= x[i]) dp[i][j] -= dp[i-1][j-x[i]];
		dp[i][j] = dp[i][j] / (m - 1);
		sum[i][j] = sum[i][j-1] + dp[i][j];
	}
	printf("%.10lf\n", sum[n][tot-1] * (m - 1) + 1);
}