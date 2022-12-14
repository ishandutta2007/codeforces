#include<bits/stdc++.h>
using namespace std;
int l[1000000],r[1000000];
vector<int> lev[1000000];
vector<int> adj[1000000];
int pa[1000000];
int tim=1;
int dp[1000000][20];
int ll[1000000];
void dfs(int v,int level)
{
    pa[level]=v;
    l[v]=tim++;
    ll[v]=level;
    lev[level].push_back(l[v]);
    for (int i=0;i<adj[v].size();i++)
        dfs(adj[v][i],level+1);
    for (int i=0;i<20;i++)
        if (level>=(1<<i))
            dp[v][i]=pa[level-(1<<i)];
    r[v]=tim-1;
}
int getParent(int v,int p)
{
    for (int i=0;i<20;i++)
        if (p & (1<<i))
            v=dp[v][i];
    return v;
}
int solve(int u,int p)
{
    int ans1=lev[p].size();
    int L=0,R=lev[p].size()-1;
    while(L<=R)
    {
        int mid=(L+R)/2;
        if (lev[p][mid]>r[u])
            ans1=mid,R=mid-1;
        else
            L=mid+1;
    }
    int ans2=-1;
    L=0,R=lev[p].size()-1;
    while(L<=R)
    {
        int mid=(L+R)/2;
        if (lev[p][mid]<l[u])
            ans2=mid,L=mid+1;
        else
            R=mid-1;
    }
    /*cout<<l[u]<<' '<<r[u]<<endl;
    for (int i=0;i<lev[p].size();i++)
        cout<<lev[p][i]<<' ';
    cout<<endl<<ans1<<' '<<ans2<<endl;*/
    return max(0,ans1-ans2-1);

}
void work()
{
    int m;
    cin>>m;
    while(m--)
    {
        int v,p;
        cin>>v>>p;
        if (p>ll[v])
            cout<<0<<' ';
        else
        {


        int u=getParent(v,p);
        int h=solve(u,ll[v]);
        cout<<h-1<<' ';

        }
    }
    cout<<endl;
}
int op[1000000];
int main()
{
    int n,m;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (x!=0)
            adj[x].push_back(i),op[i]++;
    }
    int root=1;
    for (int i=1;i<=n;i++)
        if (op[i]==0)
            dfs(i,0);
    for (int i=0;i<n;i++)
        sort(lev[i].begin(),lev[i].end());
    work();
}