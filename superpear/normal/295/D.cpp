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

const int bigp=1000000007;

int m,n,ans,e1,e2;
int f[2005][2005],g[2005][2005],sum1[2005][2005],sum2[2005][2005];

int main()
{
    scanf("%d %d",&m,&n);

    memset(f,0,sizeof(f));
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    for (int i=2;i<=n;i++)
    {
        f[1][i]=1;
        sum1[1][i]=sum1[1][i-1]+f[1][i];
        sum2[1][i]=sum2[1][i-1]+f[1][i]*(i-1);
    }
    for (int i=2;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            e1=(LL)sum1[i-1][j]*j%bigp;
            e2=(LL)sum2[i-1][j];
            e1=((e1-e2)%bigp+bigp)%bigp;
            f[i][j]=e1;
        }
        for (int j=1;j<=n;j++)
        {
            sum1[i][j]=(sum1[i][j-1]+f[i][j])%bigp;
            sum2[i][j]=(sum2[i][j-1]+(LL)f[i][j]*(j-1))%bigp;
        }
    }
    memset(g,0,sizeof(g));
    for (int i=2;i<=n;i++) g[1][i]=1;
    for (int i=2;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            e1=(LL)sum1[i-1][j-1]*j%bigp;
            e2=(LL)sum2[i-1][j-1];
            e1=((e1-e2)%bigp+bigp)%bigp;
            g[i][j]=e1;
        }
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            sum1[i][j]=(sum1[i-1][j]+f[i][j])%bigp,
            sum2[i][j]=(sum2[i-1][j]+g[i][j])%bigp;
    ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            e1=sum2[j][i];
            e2=sum1[m+1-j][i];
            ans=(ans+((LL)e1*e2%bigp)*(LL)(n-i+1)%bigp)%bigp;
        }
    printf("%d\n",ans);

    return 0;
}