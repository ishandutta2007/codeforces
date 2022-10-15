#include<bits/stdc++.h>
#define MAXN 2005
#define MOD 1000000007
using namespace std;
typedef long long ll;
string S;
ll n,k;
bool valid[MAXN];
ll dp[MAXN][MAXN][2];
ll cntone(ll x)
{
	if(x==0) return 0;
	return cntone(x>>1)+(x&1);
}
ll cal(ll i,ll x,ll f)
{
	if(x<0) return 0;
	if(x>n-i) return 0;
	if(dp[i][x][f]!=-1) return dp[i][x][f];
	if(i==n) return dp[i][x][f]=(x==0)?1:0;
	if(f)
	{
		if(S[i]=='1') return dp[i][x][f]=(cal(i+1,x-1,1)+cal(i+1,x,0))%MOD;
		else return dp[i][x][f]=cal(i+1,x,1);
	} 
	else return dp[i][x][f]=(cal(i+1,x-1,0)+cal(i+1,x,0))%MOD;
}
int main()
{
	cin>>S;
	n=S.length();
	scanf("%I64d",&k);
	if(k==0)
	{
		printf("1\n");
		return 0;
	}
	memset(valid,false,sizeof(valid));
	for(ll i=1;i<=1000;i++)
	{
		ll t=i,tt=t;
		bool f=true;
		for(ll j=0;j<k-1;j++)
		{
			if(t==1) f=false;
			t=cntone(t);
		}
		if(t==1&&f) valid[tt]=true; 
	}
	memset(dp,-1,sizeof(dp));
	ll ans=0;
	for(ll i=1;i<=1000;i++)
		if(valid[i]) ans=(ans+cal(0,i,1))%MOD;
	if(k==1) ans=(ans-1+MOD)%MOD;
	printf("%I64d\n",ans);
	return 0;
}