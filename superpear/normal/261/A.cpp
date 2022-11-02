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

int m,n,cs,minc,ans,a[1000005];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    scanf("%d",&m);
    minc=maxlongint;
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&cs);
        minc=min(minc,cs);
    }
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    ans=0;
    for (int i=1;i<=n;i++)
        if ((i-1)%(minc+2)+1<=minc) ans+=a[i];
    printf("%d\n",ans);

    return 0;
}