/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 22:59:41
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],b[MAXN];
int ans[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    int s=0,s1=0;
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
        s^=a[i];
        s1^=a[i];
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        s^=b[i];
    }
    if(s!=0) {puts("NO"); return 0;}
    puts("YES");
    for(int i=0;i<n-1;i++) ans[i][m-1]=a[i]; 
    for(int i=0;i<m-1;i++) ans[n-1][i]=b[i];
    ans[n-1][m-1]=s1^a[n-1]^b[m-1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}