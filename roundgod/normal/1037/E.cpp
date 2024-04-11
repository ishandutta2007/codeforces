/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-03 10:11:53
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
set<int> G[MAXN];
int deg[MAXN];
int u[MAXN],v[MAXN];
int ans[MAXN];
bool valid[MAXN];
set<P> s;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d",&u[i],&v[i]);
        deg[u[i]]++;deg[v[i]]++;
        G[u[i]].insert(v[i]);G[v[i]].insert(u[i]);
    }
    memset(valid,true,sizeof(valid));
    for(int i=1;i<=n;i++) s.insert(P(deg[i],i));
    for(int i=m;i>=1;i--)
    { 
        while(s.size()&&s.begin()->F<k)
        {
            int v=s.begin()->S;valid[v]=false;
            s.erase(s.begin());
            for(auto it:G[v])
            {
                if(!valid[it]) continue;
                G[it].erase(v);
                s.erase(P(deg[it],it));
                deg[it]--;
                s.insert(P(deg[it],it));
            }
        } 
        ans[i]=(int)s.size();
        if(!valid[u[i]]||!valid[v[i]]) continue;
        s.erase(P(deg[u[i]],u[i]));deg[u[i]]--;s.insert(P(deg[u[i]],u[i]));G[u[i]].erase(v[i]);
        s.erase(P(deg[v[i]],v[i]));deg[v[i]]--;s.insert(P(deg[v[i]],v[i]));G[v[i]].erase(u[i]);
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}