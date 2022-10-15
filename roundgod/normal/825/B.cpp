#include<bits/stdc++.h>
#define MAXN 10
using namespace std;
char str[MAXN][MAXN];
int a[MAXN][MAXN];
int main()
{
    for(int i=0;i<10;i++)
        scanf("%s",str[i]);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
    {
        if(str[i][j]=='.') a[i][j]=0;
        if(str[i][j]=='X') a[i][j]=1;
        if(str[i][j]=='O') a[i][j]=-1;
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<=5;j++)
    {
        if(a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]+a[i][j+4]==4)
        {
            printf("YES");
            return 0;
        }
    }
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<=5;i++)
        {
            if(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]+a[i+4][j]==4)
            {
                printf("YES");
                return 0;
            }
        }
    }
    for(int i=0;i<=5;i++)
        for(int j=0;j<=5;j++)
    {
        if(a[i][j]+a[i+1][j+1]+a[i+2][j+2]+a[i+3][j+3]+a[i+4][j+4]==4)
        {
            printf("YES");
            return 0;
        }
    }
    for(int i=4;i<10;i++)
        for(int j=0;j<=5;j++)
    {
        if(a[i][j]+a[i-1][j+1]+a[i-2][j+2]+a[i-3][j+3]+a[i-4][j+4]==4)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}