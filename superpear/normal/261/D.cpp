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

int f[20000007],maxc[100005],b[100005];
int tt,n,cs,t,maxb,len,ans;

void doit(int s,int t)
{
    while ((s<=maxb)&&(t>maxc[s]))
    {
        maxc[s]=t;
        ++s;
    }
}

int main()
{
    scanf("%d %d %d %d",&tt,&n,&maxb,&t);
    t=min(t,maxb);
    for (int gb=1;gb<=tt;gb++)
    {
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        len=t*n;
        memset(f,0,sizeof(f));
        memset(maxc,0,sizeof(maxc));
        f[1]=1,doit(b[1],f[1]);
        ans=1;
        for (int i=2;i<=len;i++)
        {
            cs=b[(i-1)%n+1];
            f[i]=maxc[cs-1]+1;
            ans=max(ans,f[i]);
            doit(cs,f[i]);
        }
        printf("%d\n",ans);
    }

    return 0;
}