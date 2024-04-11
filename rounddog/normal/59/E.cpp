#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 3005
#define inf 1000000200

using namespace std;
set <pair <int , pair <int , int> > > s;
queue <pair<int ,int> > q;

int n,m,k,a[maxn][maxn],b[maxn],ans[maxn],pre[maxn][maxn];
vector <int> e[maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    s.clear();
    for (int i=1;i<=k;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        s.insert({u,{v,w}});
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) a[i][j]=inf;
    q.push({0,1}); a[0][1]=0;
    while (!q.empty())
    {
        int u=q.front().first;
        int v=q.front().second;
        q.pop();
        for (int i=0;i<e[v].size();i++)
        {
            int w=e[v][i];
            if (v!=w&&a[v][w]==inf&&!s.count({u,{v,w}})){
                pre[v][w]=u;
                a[v][w]=a[u][v]+1;
                q.push({v,w});
            }
        }
    }
    k=1;
    for (int i=2;i<n;i++)
        if (a[i][n]<a[k][n]) k=i;
    if (a[k][n]==inf) printf("-1\n");
    else{
        ans[0]=n;ans[1]=k;int j=1;
        while (ans[j]!=1){
            ans[j+1]=pre[ans[j]][ans[j-1]];
            j++;
        }
        printf("%d\n",j);
        for (int i=j;i>0;i--) printf("%d ",ans[i]); printf("%d\n",ans[0]);
    }
    return 0;
}