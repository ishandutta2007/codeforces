#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=55;
typedef long long ll;
ll a[N],ans;
int k,n;
bool dp[N][N];
bool sol(ll cur){
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	rep(sta,k)rep(i,n){
		for(int j=0;j<i;++j)
			if(((a[i]-a[j])&cur)==cur&&dp[sta-1][j]){
				dp[sta][i]=1;break;
			}
	}
	return dp[k][n];
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n)scanf("%lld",a+i),a[i]+=a[i-1];
	for(ll tmp=1ll<<62;tmp;tmp>>=1){
		if(sol(ans|tmp))ans|=tmp;
	}
	printf("%lld\n",ans);
	//system("pause");
	return 0;
}