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

vector<double> g[3005][305];
int N,M,cs,maxk,xc,yc,now[305];
double ans,maxc,p[3005][305],kc[305];

int main()
{
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
        {
            scanf("%d",&cs);
            p[i][j]=double(cs)/1000;
        }
    for (int j=0;j<=M;j++)
    {
        g[0][j].p_b(1);
        for (int k=1;k<=N;k++)
            g[0][j].p_b(0);
    }
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
            g[i][j].p_b(g[i-1][j][0]*(1-p[i][j]));
    ans=0;
    for (int i=1;i<=M;i++)
    {
        now[i]=1,kc[i]=1;
        for (int j=1;j<=N;j++)
            kc[i]*=(1-p[j][i]);
        kc[i]=1-kc[i];
    }
    for (int i=1;i<=N;i++)
    {
        maxc=0,maxk=0;
        for (int j=1;j<=M;j++)
            if (kc[j]>maxc)
            {
                maxc=kc[j];
                maxk=j;
            }
        ans+=maxc;
        //cout<<maxk<<" "<<maxc<<endl;
        xc=maxk,yc=now[xc];
        ++now[xc];
        for (int j=1;j<=N;j++)
        {
            if (yc>=g[j][xc].size()) g[j][xc].p_b(0);
            g[j][xc][yc]=g[j-1][xc][yc]*(1-p[j][xc])+g[j-1][xc][yc-1]*p[j][xc];
        }
        //cout<<N<<" "<<xc<<" "<<yc<<" "<<g[N][xc][yc]<<endl;
        kc[xc]-=g[N][xc][yc];
    }
    printf("%.10lf\n",ans);

    return 0;
}