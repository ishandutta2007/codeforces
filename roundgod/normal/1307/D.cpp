#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
vector<int> G[MAXN];
int d1[MAXN],d2[MAXN];
bool cmp1(int x,int y)
{
    if(d1[x]!=d1[y]) return d1[x]<d1[y];
    return d2[x]>d2[y];
}
void bfs(int s,int d[])
{
    fill(d+1,d+n+1,INF);
    queue<int> que;
    d[s]=0;
    que.push(s);
    while(que.size())
    {
        int v=que.front(); que.pop();
        for(auto to:G[v])
        {
            if(d[to]==INF)
            {
                d[to]=d[v]+1;
                que.push(to);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    bfs(1,d1); bfs(n,d2);
    sort(a+1,a+k+1,cmp1);
    int maxi=0,maxs=-INF;
    for(int i=1;i<=k;i++)
    {
        maxi=max(maxi,maxs+d2[a[i]]+1);
        maxs=max(maxs,d1[a[i]]);
    }
    maxi=min(maxi,d1[n]);
    printf("%d\n",maxi);
    return 0;
}