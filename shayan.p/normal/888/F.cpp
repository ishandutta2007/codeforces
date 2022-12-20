#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1010,mod=1e9+7;
ll dp[maxn][maxn],dp2[maxn][maxn],n;
bool d[maxn][maxn],mark[maxn][maxn],mark2[maxn][maxn];
struct FandG
{
	ll f(ll a,ll b)
	{
		if(mark[a][b])return dp[a][b];
		mark[a][b]=1;
		if(a==b){dp[a][b]=1;return dp[a][b];}
		for(ll i=(a+1)%n;i!=(b+1)%n;i=(i+1)%n) 
		{
		ll tmp=g(a,i);//begin end
		dp[a][b]+=tmp*f(i,b)*d[a][i];dp[a][b]%=mod;
		}
		return dp[a][b];
	}
	ll g(ll a,ll i)
	{
		if(mark2[a][i])return dp2[a][i];
		mark2[a][i]=1;
		for(ll j=(a+1)%n;j!=(i+1)%n;j=(j+1)%n){dp2[a][i]+=f(a,((j-1)+n)%n)*f(j,i);dp2[a][i]%=mod;}
		return dp2[a][i];
	}
};
int main()
{
	cin>>n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)cin>>d[i][j];
		FandG ans;
		cout<<ans.f(1,0);
}