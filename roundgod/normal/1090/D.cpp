/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 16:43:02
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int deg[MAXN];
vector<int> G[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(m==1LL*n*(n-1)/2)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    int id1=-1,id2=-1;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]!=n-1)
        {
            id1=i;
            set<int> s;
            for(int j=1;j<=n;j++) if(j!=i) s.insert(j);
            for(auto to:G[i]) s.erase(to);
            assert(s.size()>0);
            id2=*s.begin();
            break;
        }
    }
    memset(ans,0,sizeof(ans));
    ans[id1]=1;ans[id2]=2;
    int now=3;
    for(int i=1;i<=n;i++) if(ans[i]==0) ans[i]=now++;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    ans[id2]=1;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}