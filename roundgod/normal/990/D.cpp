/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 18:32:08
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int dis[MAXN][MAXN];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    memset(dis,0,sizeof(dis));
    if(a>1&&b>1) {puts("NO"); return 0;}
    if(n==2&&a==1&&b==1)
    {
        puts("NO");
        return 0;
    }
    if(n==3&&a==1&b==1)
    {
        puts("NO");
        return 0;
    }
    if(a==1&&b==1)
    {
        for(int i=2;i<=n-1;i++)
            dis[i][1]=dis[1][i]=1;
        dis[n][n-1]=dis[n-1][n]=1;
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%d",dis[i][j]);
            puts("");
        }
        return 0;
    }
    if(b==1)
    {
        int x=n-a;
        for(int i=2;i<=1+x;i++)
            dis[i][1]=dis[1][i]=1;
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%d",dis[i][j]);
            puts("");
        }
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i==j) dis[i][j]=0; else dis[i][j]=1;
        int x=n-b;
        for(int i=2;i<=1+x;i++)
            dis[i][1]=dis[1][i]=0;
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%d",dis[i][j]);
            puts("");
        }
        return 0;
    }
    return 0;
}