#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e5+10,inf=1e18;
ll ans,Min,c[maxn];
vector<ll>v[maxn];
bool mark[maxn];
void dfs(ll ind)
{
	Min=min(Min,c[ind]);
	mark[ind]=1;
	for(ll i=0;i<v[ind].size();i++){
		ll y=v[ind][i];
		if(!mark[y])dfs(y);
	}
}
int main()
{
	ll n,m;cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>c[i];
	for(ll i=1;i<=m;i++){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	for(ll i=1;i<=n;i++){
		if(!mark[i]){
			Min=inf;
			dfs(i);
			ans+=Min;
		}
	}
	cout<<ans;
}