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

bool cmp(PII a,PII b)
{
    return (a.w1*double(a.w2)/(100-a.w2))>(b.w1*(double(b.w2)/(100-b.w2)));
}

int n,xc,pc;
double ans;
double sum[100005];
PII a[100005];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&xc,&pc);
        a[i]=m_p(xc,pc);
    }
    sort(a+1,a+n+1,cmp);
    ans=0;
    for (int i=1;i<=n;i++) ans+=a[i].w1;
    sum[n]=1-double(a[n].w2)/100;
    for (int i=n-1;i>=1;i--) sum[i]=sum[i+1]+1-double(a[i].w2)/100;
    for (int i=1;i<n;i++) ans+=double(a[i].w2)/100*a[i].w1*sum[i+1];
    printf("%.16lf\n",ans);

    return 0;
}