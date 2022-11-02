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

const int maxn=300005;

int N,ans,xc,maxk,cc,o;
int hash1[maxn],hash2[maxn],hash3[maxn],v[maxn],c[maxn],l[maxn],r[maxn],pre[maxn],mc[maxn],pf[maxn];
vector<int> sc[maxn];

void pushit(int place,int num,int flag,int ic)
{
    if ((hash1[place]!=ic)||(num>hash2[place]))
    {
        hash1[place]=ic;
        hash2[place]=num;
        hash3[place]=flag;
    }
}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d %d %d %d",&v[i],&c[i],&l[i],&r[i]);
    for (int i=1;i<=N;i++) sc[c[i]+l[i]+r[i]].p_b(i);
    ans=0;
    memset(pre,0,sizeof(pre));
    memset(mc,0,sizeof(mc));
    memset(hash1,0,sizeof(hash1));
    memset(hash2,0,sizeof(hash2));
    memset(hash3,0,sizeof(hash3));
    for (int i=0;i<=300000;i++)
        if (sc[i].size()!=0)
        {
            for (int j=0;j<sc[i].size();j++)
            {
                xc=sc[i][j];
                if (l[xc]==0)
                {
                    mc[xc]=v[xc];
                    pushit(r[xc],mc[xc],xc,i);
                }
                if (hash1[r[xc]+c[xc]]==i)
                {
                    mc[xc]=hash2[r[xc]+c[xc]]+v[xc];
                    pre[xc]=hash3[r[xc]+c[xc]];
                    pushit(r[xc],mc[xc],xc,i);
                }
            }
        }
    for (int i=1;i<=N;i++)
        if (r[i]==0)
            if (mc[i]>ans) ans=mc[i],maxk=i;
    cc=maxk;
    o=0;
    while (cc>0)
    {
        ++o,pf[o]=cc;
        cc=pre[cc];
    }
    printf("%d\n",o);
    if (o>0)
    {
        for (int i=o;i>1;i--) printf("%d ",pf[i]);printf("%d\n",pf[1]);
    }

    return 0;
}