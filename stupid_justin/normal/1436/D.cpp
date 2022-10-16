//
#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define R register
#define It vector<int>::iterator
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],fa[N];
int siz[N],sum[N],MAX[N];
int n,ans,l;
vector<int> vec[N];
void add(int u,int v)
{
	vec[u].push_back(v);
}
void dfs(int u)
{
	sum[u]=a[u];
	if (vec[u].size()==0) 
	{
		MAX[u]=a[u];
		siz[u]=1;
		return;
	}
	for (int i=0;i<vec[u].size();i++)
	{
		int v=vec[u][i];
		dfs(v);
		MAX[u]=max(MAX[u],MAX[v]);
		sum[u]+=sum[v];
		siz[u]+=siz[v];
	}
	if (MAX[u]*siz[u]<sum[u])
	{
		//
		MAX[u]=MAX[u]+(sum[u]-MAX[u]*siz[u]+siz[u]-1)/siz[u];
	}
}
signed main()
{
    cin>>n;
    for (int i=2;i<=n;i++) cin>>fa[i],add(fa[i],i);
    for (int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    cout<<MAX[1]<<endl;
}