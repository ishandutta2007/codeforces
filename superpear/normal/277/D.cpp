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
typedef pair<LL,double> PLD;

PLD f[1005][1601],ans;
int N,T,ga,cs;
int s1[1005],s2[1005],t1[1005],t2[1005];
double pf[1005];

bool equal(double a,double b)
{
    return abs(a-b)<=1e-9;
}

bool bsm(double a,double b)
{
    if (equal(a,b)) return true;
    return a>b;
}

PLD getmax(PLD a,PLD b)
{
    if (a.w1>b.w1) return a;
    if (a.w1<b.w1) return b;
    if (a.w2<b.w2) return a; else return b;
}

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d %d",&N,&T);
    for (int i=1;i<=N;i++)
        scanf("%d %d %d %d %lf",&s1[i],&s2[i],&t1[i],&t2[i],&pf[i]);
    //for (int i=1;i<=N;i++) cout<<s2[i]*pf[i]/(1-pf[i])<<endl;
    for (int i=1;i<=N;i++)
        for (int j=i+1;j<=N;j++)
            if (t2[j]*pf[j]*(1-pf[i])<=t2[i]*pf[i]*(1-pf[j]))
            {
                swap(s1[i],s1[j]);
                swap(s2[i],s2[j]);
                swap(t1[i],t1[j]);
                swap(t2[i],t2[j]);
                swap(pf[i],pf[j]);
            }
    //for (int i=1;i<=N;i++) cout<<s1[i]<<" "<<pf[i]<<" "<<s2[i]*pf[i]/(1-pf[i])<<endl;
    for (int i=0;i<=N;i++)
        for (int j=0;j<=T;j++)
            f[i][j]=m_p(-1,1e9);
    f[0][0]=m_p(0,0);
    for (int i=0;i<N;i++)
    {
        ga=round((1-pf[i+1])*1000000);
        for (int j=0;j<=T;j++)
            if (f[i][j].w1>=0)
            {
                f[i+1][j]=getmax(f[i+1][j],f[i][j]);
                if (j+t1[i+1]<=T)
                    f[i+1][j+t1[i+1]]=getmax(f[i+1][j+t1[i+1]],m_p(f[i][j].w1+(LL)s1[i+1]*1000000,f[i][j].w2+t1[i+1]));
                if (j+t1[i+1]+t2[i+1]<=T)
                {
                    cs=j+t1[i+1]+t2[i+1];
                    f[i+1][cs]=getmax(f[i+1][cs],
                                      m_p(f[i][j].w1+(LL)s1[i+1]*1000000+(LL)s2[i+1]*ga,
                                          f[i][j].w2*pf[i+1]+t1[i+1]+(j+t2[i+1])*(1-pf[i+1])
                                            )
                                      );
                }
            }
    }
    ans=m_p(-1,1e9);
    for (int i=0;i<=T;i++)
        ans=getmax(ans,f[N][i]);
    printf("%.10lf %.10lf\n",double(ans.w1)/1000000,ans.w2);

    return 0;
}