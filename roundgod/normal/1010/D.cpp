/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-27 00:03:01
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tp,x,y;
int type[MAXN];//AND:1 OR:2 XOR:3 NOT:4 IN:5
vector<int> G[MAXN];
int bit[MAXN];
bool ch[MAXN];
string str;
int dfs(int v)
{
    if(type[v]==5) return bit[v];
    else if(type[v]==4) return bit[v]=1-dfs(G[v][0]);
    else if(type[v]==3) return bit[v]=dfs(G[v][0])^dfs(G[v][1]);
    else if(type[v]==2) return bit[v]=dfs(G[v][0])|dfs(G[v][1]);
    else return bit[v]=dfs(G[v][0])&dfs(G[v][1]);
}
void solve(int v)
{
    ch[v]=true;
    if(type[v]==5) 
    {
        return;
    }
    else if(type[v]==4) 
    { 
        solve(G[v][0]); 
        return;
    }
    else if(type[v]==3) 
    {
        solve(G[v][0]); solve(G[v][1]);
        return;
    }
    else if(type[v]==2)
    {
        if(bit[v]==1&&bit[G[v][0]]==1&&bit[G[v][1]]==1) return;
        else
        {
            if(bit[v]==0) 
            {
                solve(G[v][0]);solve(G[v][1]);
            }
            else if(bit[G[v][0]]==1) solve(G[v][0]); else solve(G[v][1]);
        }
        return;
    }
    else
    {
        if(bit[v]==0&&bit[G[v][0]]==0&&bit[G[v][1]]==0) return;
        else
        {
            if(bit[v]==1) 
            {
                solve(G[v][0]);solve(G[v][1]);
            }
            else if(bit[G[v][0]]==1) solve(G[v][1]); else solve(G[v][0]);
        }
        return;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        if(str=="AND")
        {
            scanf("%d%d",&x,&y);
            G[i].push_back(x);G[i].push_back(y);type[i]=1;
        }
        else if(str=="OR")
        {
            scanf("%d%d",&x,&y);
            G[i].push_back(x);G[i].push_back(y);type[i]=2;
        }
        else if(str=="XOR")
        {
            scanf("%d%d",&x,&y);
            G[i].push_back(x);G[i].push_back(y);type[i]=3;
        }
        else if(str=="NOT")
        {
            scanf("%d",&x);
            G[i].push_back(x);type[i]=4;
        }
        else
        {
            scanf("%d",&x);
            type[i]=5;bit[i]=x;
        }
    }
    dfs(1);
    memset(ch,false,sizeof(ch));
    solve(1);
    for(int i=1;i<=n;i++)
    {
        if(type[i]==5)
        {
            if(ch[i]) printf("%d",1-bit[1]); else printf("%d",bit[1]);
        }
    }
    return 0;
}