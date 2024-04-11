#include<bits/stdc++.h>
#define int long long
const int N=1e6+5;
using namespace std;
int n,rt,cnt,sum;
int fa[N],sz[N],w[N],ans[3];
vector<int> T[N];
void add(int u,int v)
{
    T[u].push_back(v);
    T[v].push_back(u);
}
void dfs(int u) 
{
	sz[u]=w[u];
	for (int i=0;i<T[u].size();i++)
    {
        int v=T[u][i];
        if (v!=fa[u])
        {
            dfs(v);
            sz[u]+=sz[v];
        }
    }
	if (sz[u]==(sum/3) && fa[u]!=0) ans[++cnt]=u,sz[u]=0;
}

signed main() 
{
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%lld%lld",&fa[i],&w[i]);
    for (int i=1;i<=n;i++) sum+=w[i];
    for (int i=1;i<=n;i++) if (fa[i]==0) rt=i; else add(fa[i],i);
	if (sum%3!=0) {cout<<-1<<endl;return 0;}
	dfs(rt);
	if (cnt>=2) cout<<ans[1]<<" "<<ans[2]<<endl;
	else cout<<-1<<endl;
}