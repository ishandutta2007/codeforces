#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 150005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,q,cnt,d;
vector<int> G[MAXN];
int p[MAXN],dep[MAXN],pp[MAXN];
char str[MAXN],s[2];
int dp[MAXN][26][2],pos[MAXN],sum[MAXN];
void add(int v,int ch,int x)
{
    dp[v][ch][x]++;
    if(dp[v][ch][x]>dp[v][ch][x^1])
    {
        sum[v]++;
        if(sum[v]==d-dep[v]+1) cnt++;
        if(v!=1) add(pp[v],ch,pos[v]);
    }
}
void dec(int v,int ch,int x)
{
    dp[v][ch][x]--;
    if(dp[v][ch][x]>=dp[v][ch][x^1])
    {
        sum[v]--;
        if(sum[v]==d-dep[v]) cnt--;
        if(v!=1) dec(pp[v],ch,pos[v]);
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        scanf("%d %s",&p[i],s);
        str[i]=s[0];
        G[p[i]].push_back(i); dep[i]=dep[p[i]]+1; d=max(d,dep[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if((int)G[i].size()==0&&dep[i]!=d)
        {
            for(int j=0;j<q;j++) puts("Fou");
            return 0;
        }
    }
    pp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if((int)G[p[i]].size()==2) 
        {
            pos[i]=(G[p[i]][0]==i?0:1);
            pp[i]=p[i];
        }
        else
        {
            pp[i]=pp[p[i]];
            pos[i]=pos[p[i]];
        }
        if(str[i]!='?') add(pp[i],(int)str[i]-'a',pos[i]);
    }
    for(int i=0;i<q;i++)
    {
        int v;
        scanf("%d %s",&v,s);
        if(str[v]!='?') dec(pp[v],(int)str[v]-'a',pos[v]);
        str[v]=s[0];
        if(str[v]!='?') add(pp[v],(int)str[v]-'a',pos[v]);
        if(cnt) puts("Fou");
        else
        {
            int ans=0;
            for(int j=0;j<26;j++) ans+=(j+1)*(d-(sum[1]-max(dp[1][j][0],dp[1][j][1])));
            printf("Shi %d\n",ans);
        }
    }
    return 0;
}