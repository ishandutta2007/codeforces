#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,x[MAXN],y[MAXN];
vector<ll> G[MAXN];
vector<ll> rG[MAXN];
vector<ll> vs;
bool used[MAXN],valid[MAXN],circ[MAXN];
ll cmp[MAXN],cnt1[MAXN],cnt2[MAXN];
void add_edge(ll from,ll to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(ll v)
{
    used[v]=true;
    for(ll i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(ll v,ll k)
{
    used[v]=true;
    cmp[v]=k;
    for(ll i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
ll scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(ll v=0;v<200000;v++)
    {
        if(!used[v]) dfs(v);
    }
    ll k=0;
    memset(used,0,sizeof(used));
    for(ll i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&x[i],&y[i]);
		x[i]--;
		y[i]--;
		if(x[i]==y[i])
		{
			add_edge(x[i],y[i]);
			continue;
		}
		add_edge(x[i],y[i]);
		add_edge(y[i],x[i]);
	}
	ll p=scc();
	for(ll i=0;i<200000;i++)
		cnt1[cmp[i]]++;
	ll ans=1;
	memset(circ,false,sizeof(circ));
	for(ll i=0;i<n;i++)
	{
		if(x[i]==y[i]) circ[cmp[x[i]]]=true;
		cnt2[cmp[x[i]]]++;
	}
	for(ll i=0;i<p;i++)
	{
		if(cnt2[i]==0) continue;
		if(cnt2[i]==cnt1[i]-1) ans=ans*cnt1[i]%MOD; 
		else
		{
			if(circ[i]) continue; 
			else ans=ans*2%MOD;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}