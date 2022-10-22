#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b)for(ll i=a;i>=b;i--)
#define	ll long long
#define pb push_back
using namespace	std;
ll n,mark[200009],dp[200009][2],col[200009],mod=1e9+7,ans=1,x;
vector<ll>	g[200009];
ll	xgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1,gcd=xgcd(b,a%b,x1,y1);
	x=y1;
	y=x1- (long	long)(a/b)*y1;
	return	gcd;
}
ll	dfs(ll	x1){
	if(col[x1]==1){
		dp[x1][0]=0;
		dp[x1][1]=1;
		return	0;}
	mark[x1]=1;
	vector<ll>v1,v2;ll pr=1;
	f(i,0,g[x1].size()){
		if(mark[g[x1][i]]==0){
			dfs(g[x1][i]);
			pr*=((dp[g[x1][i]][0]%mod)+(dp[g[x1][i]][1]%mod))%mod;
			pr%=mod;
			v1.pb((dp[g[x1][i]][0]+dp[g[x1][i]][1])%mod);
			v2.pb(dp[g[x1][i]][1]%mod);
		}
	}
	dp[x1][0]=pr%mod;
	f(i,0,v1.size()){
		ll a,x=1,y=1,g1=xgcd(v1[i],mod,x,y);
		a= (dp[x1][0]*((x+mod)%mod))%mod;
		//cout<<a<<endl;
		dp[x1][1]+=(a*v2[i])%mod;
		dp[x1][1]%=mod;
	}
	//cout<<x1<<" : "<<dp[x1][0]<<" "<<dp[x1][1]<<endl;
	return 0;
}
int	main(){
	cin>>n;
	f(i,1,n){
		cin>>x;
		g[x].pb(i);
		g[i].pb(x);}
	f(i,0,n)	cin>>col[i];
	f(i,0,n){
		if(mark[i]==0	&&	col[i]==0){
			dfs(i);
			ans*=dp[i][1];
			ans%=mod;
		}
	}
	cout<<ans;
}