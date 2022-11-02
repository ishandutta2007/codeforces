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

const int bigp=10000007;

int H,Q,N,V,E,p,xc,yc,dg;
int hash1[15000005],hash2[15000005];
char st[10];
double ans;

void mplus(int S,int E)
{
    int e=S%bigp;
    while ((hash1[e]!=0)&&(hash1[e]!=S)) ++e;
    hash1[e]=S;
    hash2[e]+=E;
}

int getsize(int S)
{
    int e=S%bigp;
    while ((hash1[e]!=0)&&(hash1[e]!=S)) ++e;
    if (hash1[e]==0) return 0; else return hash2[e];
}

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d %d",&H,&Q);
    N=1<<H;
    memset(hash1,0,sizeof(hash1));
    memset(hash2,0,sizeof(hash2));
    for (int sc=1;sc<=Q;sc++)
    {
        scanf("%s",st);
        if (st[0]=='d')
        {
            p=1;
            ans=0;
            dg=0;
            double t=0.5;
            for (int i=1;i<=H;i++)
            {
                xc=getsize(p*2);
                yc=getsize(p*2+1);
                if (xc>=yc)
                {
                    ans+=double(max(getsize(p)-yc,dg))*t;
                    dg=max(dg,getsize(p)-xc);
                    p=p*2;
                }
                else
                {
                    ans+=double(max(getsize(p)-xc,dg))*t;
                    dg=max(dg,getsize(p)-yc);
                    p=p*2+1;
                }
                t*=0.5;
            }
            t*=2;
            ans+=double(max(getsize(p),dg))*t;
            printf("%.10lf\n",ans);
        }
        else
        {
            scanf("%d %d",&V,&E);
            while (V>0)
            {
                mplus(V,E);
                V/=2;
            }
        }
    }

    return 0;
}