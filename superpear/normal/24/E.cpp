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

int n,o,zl;
vector<PDD> s1,s2;
double xc,yc,ans;
PDD f[1000005];

bool cmp(PDD a,PDD b)
{
    return a.w2>b.w2;
}

double cross(PDD a,PDD b,PDD c)
{
    double x1=a.w1,y1=a.w2,x2=b.w1,y2=b.w2,x3=c.w1,y3=c.w2;
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}

double slope(PDD a,PDD b)
{
    if ((b.w2-a.w2)/(b.w1-a.w1)<0) return 1e10;
    return (b.w2-a.w2)/(b.w1-a.w1);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&yc,&xc);
        xc=-xc;
        if (xc<0) s1.p_b(m_p(xc,yc)); else s2.p_b(m_p(xc,yc));
    }
    sort(s1.begin(),s1.end(),cmp);
    sort(s2.begin(),s2.end(),cmp);

    int left,right,mid;

    ans=1e10;
    o=0;
    zl=0;
    for (int i=0;i<s1.size();i++)
    {
        while ((zl<s2.size())&&(s2[zl].w2>s1[i].w2))
        {
            while ((o>1)&&(cross(s2[zl],f[o],f[o-1])<0)) --o;
            ++o,f[o]=s2[zl];
            ++zl;
        }
        if (o>=1)
        {
            left=1,right=o-1;
            while (left<=right)
            {
                mid=(left+right)/2;
                if (slope(f[mid+1],f[mid])<=slope(s1[i],f[mid])) right=mid-1; else left=mid+1;
            }
            ans=min(ans,slope(s1[i],f[left]));
        }
    }
    if (ans>1e9) printf("-1\n"); else printf("%.10lf\n",ans);

    return 0;
}