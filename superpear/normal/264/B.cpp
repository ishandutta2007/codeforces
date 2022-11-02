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

const int maxn=100005;

int n,ans,maxc;
int f[maxn],a[maxn],g[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    ans=0;
    for (int i=1;i<=n;i++)
    {
        maxc=0;
        for (int j=1;j*j<=a[i];j++)
            if (a[i]%j==0)
            {
                if (j>1) maxc=max(maxc,g[j]);
                if (a[i]!=j) maxc=max(maxc,g[a[i]/j]);
            }
        f[i]=maxc+1;
        ans=max(ans,f[i]);
        for (int j=1;j*j<=a[i];j++)
            if (a[i]%j==0)
            {
                if (j>1) g[j]=max(g[j],f[i]);
                if (a[i]!=j) g[a[i]/j]=max(g[a[i]/j],f[i]);
            }
    }
    printf("%d\n",ans);

    return 0;
}