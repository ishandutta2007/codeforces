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

vector<int> f[100005];
int n,xc,yc;
int size[100005];
LL dp[100005][5];
LL ans;

LL Cn4(int n)
{
    int a1=n,a2=n-1,a3=n-2,a4=n-3;
    if (a1%2==0) a1/=2; else
    if (a2%2==0) a2/=2; else
    if (a3%2==0) a3/=2; else
    a4/=2;
    if (a1%3==0) a1/=3; else
    if (a2%3==0) a2/=3; else
    if (a3%3==0) a3/=3; else
    a4/=3;
    if (a1%2==0) a1/=2; else
    if (a2%2==0) a2/=2; else
    if (a3%2==0) a3/=2; else
    a4/=2;
    if (a1%2==0) a1/=2; else
    if (a2%2==0) a2/=2; else
    if (a3%2==0) a3/=2; else
    a4/=2;
    //cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
    LL ans=(LL)a1*a2*a3*a4;
    return ans;
}

void calcsize(int s,int fa)
{
    size[s]=1;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
        {
            calcsize(f[s][i],s);
            size[s]+=size[f[s][i]];
        }
}

void dfs3(int s,int fa)
{
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
            dfs3(f[s][i],s);
    for (int i=0;i<=f[s].size();i++)
        for (int j=0;j<=3;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
        {
            for (int j=0;j<=3;j++)
            {
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j+1]+=(LL)dp[i][j]*size[f[s][i]];
            }
        }
        else
        {
            for (int j=0;j<=3;j++)
                dp[i+1][j]=dp[i][j];
        }
    ans-=(LL)(dp[f[s].size()][3]+dp[f[s].size()][2])*(n-size[s]);
}

void dfs4(int s,int fa)
{
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
            dfs4(f[s][i],s);
    for (int i=0;i<=f[s].size();i++)
        for (int j=0;j<=4;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
        {
            for (int j=0;j<=4;j++)
            {
                dp[i+1][j]+=dp[i][j];
                if (j<4) dp[i+1][j+1]+=(LL)dp[i][j]*size[f[s][i]];
            }
        }
        else
        {
            for (int j=0;j<=4;j++)
                dp[i+1][j]=dp[i][j];
        }
    ans-=(LL)dp[f[s].size()][4]+dp[f[s].size()][3];
}

int main()
{
    scanf("%d",&n);
    ans=Cn4(n);
    for (int i=1;i<n;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(size,0,sizeof(size));
    memset(dp,0,sizeof(dp));
    calcsize(1,0);
    dfs3(1,0);
    dfs4(1,0);
    ans=(LL)ans*2;
    printf("%I64d\n",ans);

    return 0;
}