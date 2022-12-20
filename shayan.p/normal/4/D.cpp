#include<bits/stdc++.h>
#define ll long long
#define pl3 pair<pair<ll,ll>,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;
const ll maxn=5000;
vector<pl3> v;
ll n,h,w,par[maxn],dp[maxn],ans,ansid;
int main()
{
	cin>>n>>h>>w;
	for(ll i=0;i<n;i++)
	{
		ll a,b;cin>>a>>b;
		if(a>h&&b>w)v.PB(MP(MP(a,b),i+1));
	}
	if(v.empty()){cout<<0;return 0;}
	sort(v.begin(),v.end());
	for(ll i=0;i<v.size();i++)
	{
		ll Max=0,Maxid=i;
		for(ll j=0;j<i&&v[j].F.F<v[i].F.F;j++)
			if(v[j].F.S<v[i].F.S&&dp[j]>Max){Maxid=j;Max=dp[j];}
		dp[i]=Max+1;par[i]=Maxid;
		if(dp[i]>ans){ans=dp[i];ansid=i;}
	}
	deque<ll>Ans;
	while(true)
	{
		Ans.push_front(v[ansid].S);
		if(ansid==par[ansid])break;
		ansid=par[ansid];
	}
	cout<<ans<<endl;
	for(ll i=0;i<Ans.size();i++)cout<<Ans[i]<<" ";
}