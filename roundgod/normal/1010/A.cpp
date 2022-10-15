/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-26 23:07:06
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
int n,m,a[MAXN],b[MAXN];
bool C(long double x)
{
    x-=(x+m)/a[1];
    if(x<0) return false;
    for(int i=2;i<=n;i++) 
    {
        x-=(x+m)/b[i];
        if(x<0) return false;
        x-=(x+m)/a[i];
        if(x<0) return false;
    }
    x-=(x+m)/b[1];
    if(x<0) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    long double l=0,r=2e9;
    for(int i=0;i<200;i++)
    {
        double mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    if(l>1e9) puts("-1"); else printf("%.10Lf\n",l);
    return 0;
}