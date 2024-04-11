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

const int maxn=1005;
int pow2[maxn],xc[maxn],yc[maxn],zc[maxn],th[maxn],flag[maxn];
int m,n,k,bigp,ans,sc,tc;

int main()
{
    scanf("%d %d",&m,&n);
    if ((m%2)!=(n%2))
    {
        printf("%d\n",0);
        return 0;
    }
    scanf("%d",&k);
    for (int i=1;i<=k;i++) scanf("%d %d %d",&xc[i],&yc[i],&zc[i]);
    scanf("%d",&bigp);

    pow2[0]=1;
    for (int i=1;i<=1000;i++) pow2[i]=(LL)pow2[i-1]*2%bigp;

    if (m<n)
    {
        swap(m,n);
        for (int i=1;i<=k;i++) swap(xc[i],yc[i]);
    }

    memset(th,0,sizeof(th));
    for (int i=1;i<=k;i++) ++th[xc[i]];
    memset(flag,0,sizeof(flag));
    for (int i=1;i<=m;i++)
        if (th[i]==0)
        {
            flag[i]=1;
            break;
        }
    ans=1;
    for (int i=1;i<=m;i++)
        if (flag[i]==0)
        {
            sc=n;
            tc=1;
            for (int j=1;j<=k;j++)
                if (xc[j]==i) --sc,tc*=zc[j];
            if (sc==0)
            {
                if (tc==1) ans=0;
            }
            else
                ans=((LL)ans*pow2[sc-1])%bigp;
        }
    printf("%d\n",ans);

    return 0;
}