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

int tt,k,p1,flag;
LL l,r,p;

LL cheng(LL a,LL b,LL p)
{
    /*LL ans=0;
    while (b>0)
    {
        if (b%2==1) ans=(ans+a)%p;
        b/=2;
        a=a*2%p;
    }
    return ans;*/
    return (LL)a*b%p;
}

LL powc(LL a,LL b,LL p)
{
    if (b==0) return 1;
    LL d=powc(a,b/2,p);
    d=cheng(d,d,p);
    if (b%2==1) d=cheng(d,a,p);
    return d;
}

LL getans(LL s)
{
    if (k%p==0) return 1;
    LL c=powc(2,s+1,p-1);
    LL d=powc(k,c,p);
    d=(d-1+p)%p;
    return d;
}

int main()
{
	scanf("%d",&tt);
	for (int gb=1;gb<=tt;gb++)
	{
        scanf("%d %I64d %I64d %d",&k,&l,&r,&p1);
        if (k==1)
        {
            printf("%d\n",2%p1);
            continue;
        }
        p=p1;
        LL le=getans(l-1);
        LL pt=cheng(getans(r),powc(le,p-2,p),p);
        if (le==0) pt=powc(2,r-l+1,p);
        if (k%2==1)
        {
            LL ec=powc(2,r-l,p1);
            pt=cheng(pt,powc(ec,p1-2,p1),p1);
        }
        printf("%d\n",int(pt));
	}

    return 0;
}