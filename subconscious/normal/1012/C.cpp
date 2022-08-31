#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=5005;//,inf=0x3f3f3f3f;
int dp[N][3][N];
int a[N],n;
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",a+i);
	memset(dp,0x3f,sizeof dp);
	dp[1][0][0]=0;
	dp[1][1][0]=0;
	dp[2][2][1]=max(0,a[2]-a[1]+1);
	for(int i=1;i<=n+1;++i){
		for(int j=0;j<=i/2;++j){
			dp[i][0][j]=min(dp[i][0][j],min(dp[i-1][0][j],dp[i-1][2][j]));
			dp[i][1][j]=min(dp[i][1][j],min(dp[i-1][0][j],dp[i-1][2][j]));
			if(i>2)dp[i][2][j+1]=min(dp[i][2][j+1],dp[i-2][1][j]+max(0,a[i]-a[i-1]+1)+max(0,a[i-2]-a[i-1]+1));
			if(i>3)dp[i][2][j+1]=min(dp[i][2][j+1],dp[i-2][2][j]+max(0,a[i]-a[i-1]+1)+max(0,min(a[i-2],a[i-3]-1)-a[i-1]+1));
		}
	}
	//printf("%d\n",dp[1][0][0]);
	//printf("%d\n",dp[2][1][0]);
	//printf("%d\n",dp[4][2][1]);
	int ans=0;
	rep(i,(n+1)/2){
		ans=min(dp[n+1][0][i],min(dp[n+1][1][i],dp[n+1][2][i]));
		printf("%d%c",ans," \n"[i==(n+1)/2]);
	}
	//system("pause");
	return 0;
}