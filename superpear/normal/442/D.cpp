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

const int maxn=1000005;

int N,cs,ct,flag;
PII f[maxn],g[maxn];
int fa[maxn];

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d",&N);
    for (int i=1;i<=N+1;i++) f[i]=g[i]=m_p(0,i);
    for (int i=2;i<=N+1;i++)
    {
        scanf("%d",&cs);
        fa[i]=cs;
        cs=i;
        while (cs!=1)
        {
            ct=fa[cs];
            int ce=max(g[ct].w1+1,f[ct].w1);
            int cc=max(g[cs].w1+1,f[cs].w1);
            if (cs==f[ct].w2)
                f[ct].w1=cc;
            else
                if (cs==g[ct].w2)
                {
                    g[ct].w1=cc;
                    if (g[ct]>f[ct]) swap(g[ct],f[ct]);
                }
                else
                {
                    if (cc>=f[ct].w1)
                    {
                        g[ct]=f[ct];
                        f[ct].w1=cc,f[ct].w2=cs;
                    }
                    else
                        if (cc>g[ct].w1)
                        {
                            g[ct].w1=cc;
                            g[ct].w2=cs;
                        }
                }
            if (max(g[ct].w1+1,f[ct].w1)==ce) break;
            cs=ct;
        }
        printf("%d ",f[1].w1);
        /*if (i==16)
        {
            for (int j=1;j<=N;j++) cout<<f[j].w1<<" "<<f[j].w2<<"   "<<g[j].w1<<" "<<g[j].w2<<endl;
        }*/
    }
    printf("\n");

    return 0;
}