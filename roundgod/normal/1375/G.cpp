#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 200005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
int cnt,color[MAXN];
void dfs(int v,int p,int c)
{
    color[v]=c; if(c==0) cnt++;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,c^1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,0);
    printf("%d\n",min(cnt,n-cnt)-1);
    return 0;
}