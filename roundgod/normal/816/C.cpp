#include<bits/stdc++.h>
#define MAXN 105
#define INF 100000
using namespace std;
int n,m,graph[MAXN][MAXN],x;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
           scanf("%d",&graph[i][j]);
    x=INF;
    int p=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
           if(graph[i][j]<x)
    {
        x=graph[i][j];
        p=i;
    }
    for(int i=0;i<m;i++)
    {
        int q=graph[0][i];
        graph[0][i]=graph[p][i];
        graph[p][i]=q;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(graph[i][j]-graph[0][j]!=graph[i][0]-graph[0][0])
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    int ans=INF,t=0;
    for(int i=0;i<=x;i++)
    {
        int s=0,f=1;
        s+=i;
        for(int j=0;j<m;j++)
            s+=graph[0][j]-i;
        for(int j=1;j<n;j++)
            s+=graph[j][0]-graph[0][0]+i;
        if(s<ans)
        {
            ans=s;
            t=i;
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<t;i++)
        printf("row %d\n",p+1);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<graph[0][i]-t;j++)
            printf("col %d\n",i+1);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<graph[i][0]-graph[0][0]+t;j++)
          if(i!=p)printf("row %d\n",i+1); else printf("row 1\n");
    }
    return 0;
}