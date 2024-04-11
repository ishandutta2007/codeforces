/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 23:42:07
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define l first
#define r second
using namespace std;
typedef long double db;
typedef pair<db,db> P;
int s,ll,rr,n,q;
int sum[MAXN];
P a[MAXN];
int main()
{
    scanf("%d%d%d",&s,&ll,&rr);s=-s;
    scanf("%d",&n);
    a[0]=P(0,0);
    for(int i=1;i<=n;i++) scanf("%Lf%Lf",&a[i].l,&a[i].r);
    a[n+1]=P(INF+1,INF+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(int)(a[i].r-a[i].l);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int qx,qy;
        scanf("%d%d",&qx,&qy);
        db L=(db)(qx-ll)*s/(qy+s)+ll;
        db R=(db)(qx-rr)*s/(qy+s)+rr;
        int lid=upper_bound(a,a+n+2,P(L,L))-a; lid--;
        int rid=upper_bound(a,a+n+2,P(R,R))-a; rid--;
        db len=R-L;
        //printf("%.10Lf %10Lf\n",L,R);
        db res=0;
        if(lid==rid)
        {
            res=min(a[rid].r,R)-(db)max(a[rid].l,L);
            res=max(res,(db)0);
        }
        else
        {
            if(L<a[lid].r) res+=a[lid].r-L;
            if(a[rid].r>R) res+=R-a[rid].l; else rid++;
            res+=sum[rid-1]-sum[lid];
        }
        printf("%.10Lf\n",res/len*(rr-ll));
    }
    return 0;
}