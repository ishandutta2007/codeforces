/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-26 23:43:38
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int rec[50];
int main()
{
    scanf("%d%d",&m,&n);
    int ans;
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",m);
        fflush(stdout);
        scanf("%d",&ans);
        if(ans==0) return 0;
        if(ans==1) rec[i]=-1; else rec[i]=1;
    }
    int l=0,r=m+1;
    for(int i=1;i<=30;i++)
    {
        int mid=(l+r)/2;
        printf("%d\n",mid);
        fflush(stdout);
        scanf("%d",&ans);
        if(ans==0) return 0;
        ans*=rec[(i-1)%n+1];
        if(ans==1) l=mid; else r=mid;
    }
    return 0;
}