#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

LL n,u,v,l,r,pow2[70];
int m,bigp,ans;

void search(LL nownum,int depth,LL l,LL r,LL left,LL right)
{
    LL mid=(left+right)/2;
    if ((left==l)&&(right==r))
    {
        LL u1=u-nownum,v1=v-nownum;
        if (u1<0) u1=0;
        if (v1<u1) return;
        if (u1!=0) u1=(u1-1)/pow2[depth]+1;
        v1=v1/pow2[depth];
        LL c1=u1+v1,c2=v1-u1+1;
        if (c1%2==0) c1/=2; else c2/=2;
        c1%=bigp,c2%=bigp;
        ans=((LL)ans+((LL)c1*c2%bigp)*(LL)(pow2[depth]%bigp)+(LL)(v1-u1+1)*(nownum+1)%bigp)%bigp;
    }
    else
    {
        if (l<=mid) search(nownum,depth+1,l,min(r,mid),left,mid);
        if (r>=mid+1) search(nownum+pow2[depth],depth+1,max(l,mid+1),r,mid+1,right);
    }
}

int main()
{
    pow2[0]=1;
    for (int i=1;i<=62;i++)
        pow2[i]=pow2[i-1]*2;
    scanf("%I64d %d %d",&n,&m,&bigp);
    for (int i=1;i<=m;i++)
    {
        scanf("%I64d %I64d %I64d %I64d",&l,&r,&u,&v);
        if (u>n) ans=0; else
        {
            if (v>n) v=n;
            --u,--v;
            ans=0;
            search(0,0,l,r,1,n);
        }
        printf("%d\n",ans);
    }

    return 0;
}