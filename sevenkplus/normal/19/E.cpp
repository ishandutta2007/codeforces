#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 11111
#define pb push_back
vector<int> a[N],b[N];
int v[N],f[N],g[N],e[N],c[N],n,m,oc,ox;
void ff(int x,int fa,int C)
{
    v[x]=1,c[x]=C;
    for(int i=0,y,z;i<a[x].size();i++)
    {
        y=a[x][i],z=b[x][i];
        if(y==fa)continue;
        if(v[y]==0)e[y]=z,ff(y,x,1-C),f[x]+=f[y],g[x]+=g[y];else
        if(v[y]==1)if(c[y]==c[x])oc++,ox=z,g[x]++;else f[x]++;else
        if(v[y]==2)if(c[y]==c[x])g[x]--;else f[x]--;
    }
    v[x]=2;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),a[x].pb(y),a[y].pb(x),b[x].pb(i),b[y].pb(i);
    for(int i=1;i<=n;i++)if(!v[i])ff(i,0,0);
    vector<int> S;
    if(oc==0)for(int i=1;i<=m;i++)S.pb(i);else
    {
        if(oc==1)S.pb(ox);
        for(int i=1;i<=n;i++)if(g[i]==oc&&f[i]==0)S.pb(e[i]);
        sort(S.begin(),S.end());
    }
    printf("%d\n",S.size());for(int i=0;i<S.size();i++)printf("%d%c",S[i],i==S.size()-1?'\n':' ');
    return 0;
}