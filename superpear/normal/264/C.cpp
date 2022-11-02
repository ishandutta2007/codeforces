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
typedef pair<LL,int> PLI;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;

int n,tt,ai,bi;
int a[maxn],v[maxn];
LL maxc[maxn],f[maxn],ans;
PLI max1,max2,cs;

int main()
{
    scanf("%d %d",&n,&tt);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&v[i]);
    for (int gb=1;gb<=tt;gb++)
    {
        scanf("%d %d",&ai,&bi);
        for (int i=1;i<=n;i++) maxc[i]=-100000000000000000LL;
        max1=m_p(0,-1);
        max2=m_p(0,-1);
        ans=0;
        for (int i=1;i<=n;i++)
        {
            f[i]=maxc[v[i]]+(LL)a[i]*ai;
            if (max1.w2!=v[i]) f[i]=max(f[i],max1.w1+(LL)a[i]*bi);
                         else  f[i]=max(f[i],max2.w1+(LL)a[i]*bi);
            ans=max(ans,f[i]);
            maxc[v[i]]=max(maxc[v[i]],f[i]);
            if (v[i]==max1.w2)
                max1.w1=max(max1.w1,maxc[v[i]]);
            else
            {
                if (v[i]==max2.w2)
                {
                    max2.w1=max(max2.w1,maxc[v[i]]);
                    if (max2.w1>max1.w1) swap(max1,max2);
                }
                else
                    if ((v[i]!=max1.w2)&&(v[i]!=max2.w2))
                    {
                        cs=m_p(maxc[v[i]],v[i]);
                        if (cs>max1)
                        {
                            max2=max1,max1=cs;
                        }
                        else
                            if (cs>max2) max2=cs;
                    }
            }
        }
        printf("%I64d\n",ans);
    }

    return 0;
}