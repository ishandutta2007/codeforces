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
#include <ctime>

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

const int maxn=1000006;

struct query
{
    int l,r,bel;
    // left node in the range [l,r]   right node >=r
} C[300005];

int f[maxn];
int N,M,O,cq,o,sc;
int x[300005],y[300005],a[300005],ans[300005];
PII ls[300005];

void mplus(int s)
{
    while (s<=maxn)
    {
        ++f[s];
        s+=s&(-s);
    }
}

int getsum(int s)
{
    int ans=0;
    while (s>0)
    {
        ans+=f[s];
        s-=s&(-s);
    }
    return ans;
}

bool cmp(PII a,PII b)
{
    return a.w2>b.w2;
}

bool cmp2(query a,query b)
{
    return a.r>b.r;
}

int main()
{
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;i++) scanf("%d %d",&x[i],&y[i]);
    memset(ans,0,sizeof(ans));
    o=0;
    for (int i=1;i<=M;i++)
    {
        scanf("%d",&sc);
        for (int j=1;j<=sc;j++) scanf("%d",&a[j]);
        a[0]=0;
        for (int j=1;j<=sc;j++)
        {
            ++o,
            C[o].l=a[j-1]+1;
            C[o].r=a[j];
            C[o].bel=i;
        }
    }
    memset(f,0,sizeof(f));
    for (int i=1;i<=N;i++) ls[i]=m_p(x[i],y[i]);
    sort(ls+1,ls+N+1,cmp);
    for (int i=1;i<=N;i++) x[i]=ls[i].w1,y[i]=ls[i].w2;
    sort(C+1,C+o+1,cmp2);

    cq=1;
    for (int i=1;i<=o;i++)
    {
        while ((cq<=N)&&(y[cq]>=C[i].r))
        {
            mplus(x[cq]);
            ++cq;
        }
        ans[C[i].bel]+=getsum(C[i].r)-getsum(C[i].l-1);
    }
    for (int i=1;i<=M;i++) printf("%d\n",ans[i]);

    return 0;
}