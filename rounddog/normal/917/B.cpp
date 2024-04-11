#include<bits/stdc++.h>
#define maxn 150
#define x first
#define y second

using namespace std;
typedef pair<int,int> pi;
vector <pi> h[maxn];

char c[1];
int a[maxn],f[maxn][maxn][26],d[maxn],n,m,num[maxn],cnt;

int main()
{
    scanf("%d%d",&n,&m);
    memset(d,0,sizeof(d));
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d%s",&u,&v,c);
        d[v]++; h[u].push_back({v,c[0]-'a'});
    }
    queue <int> q;
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;i++) if (!d[i]) q.push(i); cnt=n;
    while (!q.empty())
    {
        int u=q.front(); q.pop(); a[u]=cnt;
        num[cnt--]=u;
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i].x;
            d[v]--;
            if (!d[v]) q.push(v);
        }
    }
    for (int i=1;i<=n;i++)
    {
        int u=num[i];
        for (int j=0;j<26;j++) f[i][i][j]=false;
    }
    for (int ij=2;ij<=n+n;ij++)
    {
        for (int i=max(1,ij-n);i<=min(n,ij-1);i++)
        {
            int j=ij-i; int u=num[i];
            for (int k=0;k<26;k++)
            {
                f[i][j][k]=false;
                for (int ii=0;ii<h[u].size();ii++)
                {
                    int v=h[u][ii].x;
                    //if (i==3&&j==2&&k==0) printf("%d %d %d\n",j,a[v],h[u][ii].y);
                    if (h[u][ii].y>=k) f[i][j][k]|=(!f[j][a[v]][h[u][ii].y]);
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) if (f[a[i]][a[j]][0]) printf("A"); else printf("B");
        printf("\n");
    }
    return 0;
}