/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-08 22:34:27
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4200
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,p;
int a[MAXN],w[MAXN];
int cnt[MAXN];
int cost[MAXN][MAXN];
int save[MAXN][MAXN];
char str[20];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=n-1;i>=0;i--) scanf("%d",&w[i]);
    int comb=(1<<n)-1;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)) a[i]+=w[j];
        }
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
            cost[i][j]=a[comb^(i^j)];
    for(int i=0;i<m;i++)
    {
        scanf("%s",str);
        int res=0;
        for(int j=0;j<n;j++) res=res*2+str[j]-'0';
        cnt[res]++;
    }
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
            save[i][cost[i][j]]+=cnt[j];
    for(int i=0;i<(1<<n);i++)
        for(int j=1;j<=200;j++) save[i][j]=save[i][j]+save[i][j-1];
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        int res=0;
        for(int j=0;j<n;j++) res=res*2+str[j]-'0';
        scanf("%d",&p);
        if(p>=1200) p=1200;
        printf("%d\n",save[res][p]);
    }
    return 0;
}