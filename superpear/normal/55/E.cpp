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

LL ans;
int N,tt,xc,yc,o,sc,k1,k2,f1,f2,cc;
int x[100005],y[100005];

int cross(int x1,int y1,int x2,int y2,int x3,int y3)
{
    x2-=x1,y2-=y1;
    x3-=x1,y3-=y1;
    LL c=(LL)x2*y3-(LL)x3*y2;
    if (c>0) return 1;
    if (c<0) return -1;
    return 0;
}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d %d",&x[i],&y[i]);
    x[N+1]=x[1],y[N+1]=y[1];
    scanf("%d",&tt);
    for (int gb=1;gb<=tt;gb++)
    {
        scanf("%d %d",&xc,&yc);
        f1=0;
        f2=0;
        for (int i=1;i<=N;i++)
        {
            cc=cross(xc,yc,x[i],y[i],x[i+1],y[i+1]);
            if (cc>0) f1=1;
            if (cc<0) f2=1;
        }
        if (f1+f2==2)
        {
            printf("0\n");
            continue;
        }
        o=1;
        ans=0;
        for (int i=1;i<=N;i++)
        {
            while (true)
            {
                sc=o%N+1;
                if (cross(x[i],y[i],x[sc],y[sc],xc,yc)>0) break;
                ++o;
            }
            k1=o-i;
            k2=N-1-k1;
            //cout<<k1<<" "<<k2<<endl;
            ans+=((LL)k1*(k1-1)/2)+((LL)k2*(k2-1)/2);
        }
        ans=(LL)N*(N-1)*(N-2)/6-ans/2;
        printf("%I64d\n",ans);
    }

    return 0;
}