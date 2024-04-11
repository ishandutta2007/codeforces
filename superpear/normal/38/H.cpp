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

int N,M,xc,yc,zc,g1,g2,s1,s2;
int dis[55][55],f1[55],f2[55],f3[55],maxc[55],minc[55];
LL f[55][55][55];

int main()
{
    scanf("%d %d",&N,&M);
    memset(dis,127,sizeof(dis));
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d %d",&xc,&yc,&zc);
        dis[xc][yc]=min(dis[xc][yc],zc);
        dis[yc][xc]=min(dis[yc][xc],zc);
    }
    scanf("%d %d %d %d",&g1,&g2,&s1,&s2);
    for (int k=1;k<=N;k++)
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if ((dis[i][k]!=biglongint)&&(dis[k][j]!=biglongint))
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    memset(maxc,0,sizeof(maxc));
    memset(minc,127,sizeof(minc));
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            if (i!=j)
            {
                maxc[i]=max(maxc[i],dis[i][j]*100+i);
                minc[i]=min(minc[i],dis[i][j]*100+i);
                dis[i][j]*=100;
                dis[i][j]+=i;
            }
    LL ans=0;
    for (int gold=1;gold<=N;gold++)
        for (int brz=1;brz<=N;brz++)
            if ((gold!=brz)&&(minc[gold]<maxc[brz]))
            {
                memset(f1,0,sizeof(f1));
                memset(f2,0,sizeof(f2));
                memset(f3,0,sizeof(f3));
                for (int i=1;i<=N;i++)
                {
                    if (minc[i]<=minc[gold]) f1[i]=1;
                    if (maxc[i]>=maxc[brz]) f3[i]=1;
                    for (int j=1;j<=N;j++)
                        if (i!=j)
                            if ((dis[i][j]>minc[gold])&&(dis[i][j]<maxc[brz]))
                                f2[i]=1;
                }
                f1[brz]=f2[brz]=f2[gold]=f3[gold]=0;
                memset(f,0,sizeof(f));
                f[0][0][0]=1;
                for (int i=0;i<N;i++)
                    for (int j=0;j<=N;j++)
                        for (int k=0;k<=N;k++)
                            if (f[i][j][k]!=0)
                            {
                                if (f1[i+1]==1)
                                    f[i+1][j+1][k]+=f[i][j][k];
                                if (f2[i+1]==1)
                                    f[i+1][j][k+1]+=f[i][j][k];
                                if (f3[i+1]==1)
                                    f[i+1][j][k]+=f[i][j][k];
                            }
                for (int i=g1;i<=g2;i++)
                    for (int j=s1;j<=s2;j++)
                        ans+=f[N][i][j];
            }
    printf("%I64d\n",ans);

    return 0;
}