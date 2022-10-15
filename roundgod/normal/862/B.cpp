#include<bits/stdc++.h>
#define MAXV 100020
using namespace std;
typedef long long ll;
vector<ll> G[MAXV];
ll a,b,n;
bool used[MAXV];
void dfs(ll v,int d)
{
   if(d==1) a++; else b++;
   used[v]=true;
   for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i],1-d);
   return;
}
int main()
{
    a=0,b=0;
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(0,0);
    printf("%I64d\n",a*b-(n-1));
    return 0;
}