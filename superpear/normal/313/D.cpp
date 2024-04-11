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

LL dp[305][305],f[305][305];
int M,N,K,xc,yc,wc;
LL ans;
vector<PII> a[305];

void mplus(int x,int y,LL num)
{
    while (y<=N)
    {
        f[x][y]=min(f[x][y],num);
        y+=y&(-y);
    }
}

LL getmin(int x,int l,int r)
{
    LL ans=(LL)biglongint*biglongint;
    if (l==0) ans=min(ans,dp[x][0]),++l;
    while (r>=l)
    {
        if (r-(r&(-r))>=l)
            ans=min(ans,f[x][r]),
            r-=r&(-r);
        else
            ans=min(ans,dp[r][x]),
            r--;
    }
    return ans;
}

int main()
{
    scanf("%d %d %d",&N,&M,&K);
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d %d",&xc,&yc,&wc);
        a[yc].p_b(m_p(xc,wc));
    }
    for (int i=0;i<=N;i++)
        for (int j=0;j<=N;j++)
            dp[i][j]=(LL)biglongint*biglongint,
            f[i][j]=(LL)biglongint*biglongint;
    dp[0][0]=0;
    for (int i=1;i<=N;i++)
        for (int j=0;j<=N-K;j++)
        {
            if (j>0) dp[i][j]=dp[i-1][j-1];
            for (int k=0;k<a[i].size();k++)
                dp[i][j]=min(dp[i][j],getmin(j,a[i][k].w1-1,i-1)+a[i][k].w2);
            mplus(j,i,dp[i][j]);
        }
    ans=(LL)biglongint*biglongint;
    for (int j=0;j<=N-K;j++)
        ans=min(ans,dp[N][j]);
    if (ans==(LL)biglongint*biglongint) ans=-1;
    cout<<ans<<endl;

    return 0;
}