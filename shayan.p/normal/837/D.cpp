#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18+10;
const ll maxn=210;
ll dp[2][maxn][25*maxn];//the maaximum fives we can get using i numbers which has j 2s
int main()
{
	ll n,k;cin>>n>>k;
	for(ll i=0;i<2;i++)//necessary??
		for(ll j=0;j<=k;j++)
			for(ll k=1;k<25*maxn;k++) dp[i][j][k]=-inf;//residan be in tedad 2  is impossible
			
	ll o,O;	
	for(ll i=1;i<=n;i++)// 1 indexed
	{
		o=i%2,O=(i+1)%2;
		ll x;scanf("%lld",&x);
		ll two=0,five=0;
		while(x%2==0) {two++;x/=2;}
		while(x%5==0) {five++;x/=5;}
		dp[o][0][0]=0;
		for(ll j=1;j<=min(i,k);j++)
			for(ll q=0;q<25*maxn;q++)
			if(q-five<0) dp[o][j][q]=dp[O][j][q];
			else if(dp[O][j][q]==-inf&&dp[O][j-1][q-five]==-inf) dp[o][j][q]=-inf;
			else dp[o][j][q]=max(dp[O][j][q],dp[O][j-1][q-five]+two);
	}
	ll Max=-inf;
	for(ll i=0;i<25*maxn;i++) Max=max(Max,min(dp[o][k][i],i));
	cout<<Max;
}