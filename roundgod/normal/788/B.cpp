#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
ll n,m;
vector<int> G[MAXN];
bool used[MAXN],valid[MAXN];
ll cnt=0;
void dfs(ll v)
{
	cnt++;
	used[v]=true;
	for(ll i=0;i<G[v].size();i++)
		if(!used[G[v][i]]) dfs(G[v][i]);
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	ll sum=0,t=-1;
	memset(valid,false,sizeof(valid));
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		x--;y--;
		t=x;
		if(x==y) {sum++; valid[x]=true; continue;}
		G[x].push_back(y);
		G[y].push_back(x);
		valid[x]=valid[y]=true;
	}
	ll num=0;
	for(ll i=0;i<n;i++)
		if(valid[i]) num++;
	memset(used,false,sizeof(used));
	dfs(t);
	if(cnt!=num)
	{
		puts("0");
		return 0;
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		if(G[i].size()<2) continue;
		else ans+=(ll)G[i].size()*((ll)G[i].size()-1)/2;
	}
	ans+=sum*(m-sum)+sum*(sum-1)/2;
	printf("%I64d\n",ans);
    return 0;
}