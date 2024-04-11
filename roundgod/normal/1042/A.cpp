/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-17 16:02:16
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
int n,m,a[MAXN];
bool C(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>x) return false;
        if(a[i]<x) cnt+=x-a[i];
    }
    return cnt>=m;
}
int main()
{
    scanf("%d%d",&n,&m);
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
    }
    int l=0,r=100000;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%d %d\n",r,mx+m);
    return 0;
}