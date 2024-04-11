#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool g[13][13]={};
struct lca{int a,b,c;} ls[110];
int n,m,q;
ll dp[15][8192];
bool check1(int r1,int m1,int r2,int m2)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(g[i][j])
            {
                if(((m1>>i)&1)&&((m2>>j)&1)&&(r1!=i||r2!=j))
                    return false;
            }
    return true;
}
bool check2(int r1,int m1,int r2,int m2)
{
    for(int i=0;i<q;i++)
    {
        if( !((1<<ls[i].a)&(m1|m2)) || !((1<<ls[i].b)&(m1|m2)) )
            continue;
        if( bool((1<<ls[i].a)&m1)^bool((1<<ls[i].b)&m1) )
        {
            if(ls[i].c!=r1) return false;
        }
        else
        {
            if( bool((1<<ls[i].a)&m1)^bool((1<<ls[i].c)&m1) )
                return false;
        }
    }
    return true;
}
ll solve(int root,int mask)
{
//  cout<<"sovle: "<<root<<
    if(dp[root][mask]!=-1)
        return dp[root][mask];
    int tmask=mask^(1<<root);
    if(tmask==0) return dp[root][mask]=1;
    int lbit=tmask&-tmask;
    tmask^=lbit;
    int tnm=tmask;
    ll ans=0;
    do{
        int nm=tnm^lbit;
        for(int i=0;i<n;i++)
            if(((1<<i)&nm)&&check1(root,mask^nm,i,nm)&&check2(root,mask^nm,i,nm))
            {
                ans+=solve(root,mask^nm)*solve(i,nm);
            }
    }while((tnm=(tnm-1)&tmask)!=tmask);
    return dp[root][mask]=ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m>>q;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--; v--;
        g[u][v]=g[v][u]=1;
    }
    for(int i=0;i<q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;c--;
        ls[i]={a,b,c};
    }
    
    memset(dp,-1,sizeof dp);
    cout<<solve(0,(1<<n)-1)<<endl;
}