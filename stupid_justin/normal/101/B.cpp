#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int dp[N],sum[N];
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> > road(m);
    vector<int> v(m);
	for(int i=0,s,t;i<m;i++)
	{
		cin>>s>>t;
		road[i]=mp(t,s);
		v[i]=t;
	}
	sort(road.begin(),road.end());
	sort(v.begin(),v.end());
	for(int i=0;i<m;i++){
		int x=road[i].second,y=road[i].first;
		if(x==0) dp[i]=1;
		int start=lower_bound(v.begin(),v.end(),x)-v.begin();
		int end=lower_bound(v.begin(),v.end(),y)-v.begin();
		dp[i]=(dp[i]+sum[end]-sum[start]+mod)%mod;
		sum[i+1]=(sum[i]+dp[i])%mod;
	}
	int ans=0;
	for(int i=0;i<m;i++)
		if(road[i].first==n)
			ans=(ans+dp[i])%mod;
	cout<<ans<<endl;
}