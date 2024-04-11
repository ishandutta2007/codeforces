#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
ll a[1000050],m,n,dp[1200][1200];
ll f(int idx,ll total){
	if(total%m==0 && total>0)return 1;
	if(idx==0)return 0;
	total%=m;
	if(dp[idx][total]!=-1)return dp[idx][total];
	return dp[idx][total]=max( f(idx-1,total+a[idx]) , f(idx-1,total) );
}
int main(){
	cin>>n>>m;
	if(n>=m){
			cout<<"YES"<<endl;
			return 0;
	}
	rep(i,n){
		scanf("%lld",&a[i]);
		if(a[i]==0){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	memset(dp,-1,sizeof(dp));
	if(f(n,0))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}