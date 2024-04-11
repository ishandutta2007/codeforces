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

int N,x,ans,sum,e0,e1,jc,c1,c2;
int a[55][55];
int b[55];

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            scanf("%d",&a[i][j]);
    x=(N+1)/2;
    ans=0;

    memset(b,0,sizeof(b));
    while (b[0]==0)
    {
        sum=0;
        for (int i=1;i<x;i++)
        {
            //now flip[x][i]=0
            e0=a[x][i];
            if (b[x]==0) e0+=a[x][i+x]; else e0-=a[x][i+x];
            for (int j=1;j<x;j++)
            {
                c1=0,c2=0;
                c1=a[j][i]+a[j+x][i];
                if (b[j]==0) c1+=a[j][i+x]; else c1-=a[j][i+x];
                if ((b[j]^b[x])==0) c1+=a[j+x][i+x]; else c1-=a[j+x][i+x];
                c2=-a[j][i]-a[j+x][i];
                if (b[j]==0) c2-=a[j][i+x]; else c2+=a[j][i+x];
                if ((b[j]^b[x])==0) c2-=a[j+x][i+x]; else c2+=a[j+x][i+x];
                e0+=max(c1,c2);
            }
            //now flip[x][i]=1
            e1=-a[x][i];
            if (b[x]==0) e1-=a[x][i+x]; else e1+=a[x][i+x];
            for (int j=1;j<x;j++)
            {
                c1=0,c2=0;
                c1=a[j][i]-a[j+x][i];
                if (b[j]==0) c1+=a[j][i+x]; else c1-=a[j][i+x];
                if ((b[j]^b[x])==0) c1-=a[j+x][i+x]; else c1+=a[j+x][i+x];
                c2=-a[j][i]+a[j+x][i];
                if (b[j]==0) c2-=a[j][i+x]; else c2+=a[j][i+x];
                if ((b[j]^b[x])==0) c2+=a[j+x][i+x]; else c2-=a[j+x][i+x];
                e1+=max(c1,c2);
            }
            sum+=max(e0,e1);
        }
        for (int i=1;i<=x;i++)
            if (b[i]==0) sum+=a[i][x]; else sum-=a[i][x];
        for (int i=x+1;i<=N;i++)
            if ((b[i-x]^b[x])==0) sum+=a[i][x]; else sum-=a[i][x];
        ans=max(ans,sum);
        jc=x;
        while (b[jc]==1)
        {
            b[jc]=0;
            --jc;
        }
        ++b[jc];
    }

    printf("%d\n",ans);

    return 0;
}