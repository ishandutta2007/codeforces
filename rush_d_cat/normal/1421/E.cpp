#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;LL a[N];
LL dp[N][3][2][2];
void upd(LL &x,LL y) {
	x=max(x,y);
}
void upd(int i,int r,int las,int flag) {
	// +
	upd(dp[i+1][r][1][flag | (las==1)],dp[i][r][las][flag] + a[i+1]);
	// -
	upd(dp[i+1][(r+1)%3][0][flag | (las==0)], dp[i][r][las][flag] - a[i+1]);
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==1) {
		return !printf("%lld\n", a[1]);
	}
	for(int i=0;i<N;i++)for(int j=0;j<3;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)dp[i][j][k][l]=-1e18;
	dp[1][0][1][0]=a[1];
	dp[1][1][0][0]=-a[1];
	for(int i=1;i<n;i++)for(int r=0;r<3;r++)for(int las=0;las<2;las++)for(int flag=0;flag<2;flag++)
			upd(i,r,las,flag);

	// n + ? =1
	int need=((1-n)%3+3)%3;
	printf("%lld\n", max(dp[n][need][0][1], dp[n][need][1][1]));
}