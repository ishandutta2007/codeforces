#include <bits/stdc++.h>
using namespace std;
bool vis[4000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=3*n;i++)vis[i]=0;
        vector<int> E;
        for (int i=0;i<m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            if (!vis[u] && !vis[v])
            {
                E.push_back(i+1);
                vis[u]=1;
                vis[v]=1;
            }
        }
        if (E.size()>=n) {
            puts("Matching");
            for (int i=0;i<n;i++)
                printf("%d ",E[i]);
        } else {
            puts("IndSet");
            int num=0;
            for (int i=1;i<=3*n;i++)
            {
                if (!vis[i])printf("%d ",i),num++;
                if (num==n)break;
            }
        }
    }
}