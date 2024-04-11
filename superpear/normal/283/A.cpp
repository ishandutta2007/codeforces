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

const int maxn=200005;

LL sum=0,ej;
int n,m,cs,dx,flag;
LL f[maxn];
int a[maxn];

void mplus(int s,LL num)
{
    while (s<=maxn)
    {
        f[s]+=num;
        s+=s&(-s);
    }
}

LL getsum(int s)
{
    LL e=0;
    while (s>0)
    {
        e+=f[s];
        s-=s&(-s);
    }
    return e;
}

int main()
{
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    m=1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&flag);
        if (flag==2)
        {
            scanf("%d",&cs);
            sum+=cs;
            ej=getsum(m+1);
            mplus(m+1,-ej);
            m++;
            a[m]=cs;
        }
        else
        if (flag==1)
        {
            scanf("%d %d",&cs,&dx);
            sum+=(LL)cs*dx;
            mplus(1,dx);
            mplus(cs+1,-dx);
        }
        else
        if (flag==3)
        {
            --m;
            sum-=getsum(m+1)+a[m+1];
        }
        printf("%.10lf\n",double(sum)/double(m));
    }
    return 0;
}