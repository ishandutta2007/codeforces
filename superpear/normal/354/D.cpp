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

const int maxn=100005;

vector<int> f[maxn];
int dp[2][1005];
int N,K,xc,yc,E;

int getsum(int i,int s)
{
    vector<int>::iterator cf=l_b(f[i].begin(),f[i].end(),s+1);
    return cf-f[i].begin();
}

int main()
{
    scanf("%d %d",&N,&K);
    for (int i=1;i<=K;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[yc].p_b(xc);
    }
    for (int i=1;i<=N;i++)
        sort(f[i].begin(),f[i].end());
    dp[1][1]=0;
    dp[1][0]=getsum(N,N)*3;
    E=1000;
    int x1,x2;
    for (int i=1;i<=N;i++)
    {
        x1=i%2,x2=1-x1;
        for (int j=0;j<=1000;j++) dp[x2][j]=biglongint;
        for (int j=1;j<=min(i,E);j++)
            dp[x1][j]=min(dp[x1][j],dp[x1][j-1]);
        for (int j=min(i,E);j>=0;j--)
            if (dp[x1][j]!=biglongint)
            {
                dp[x1][0]=min(dp[x1][0],j*(j+1)/2+dp[x1][j]+2);
                dp[x2][j+1]=min(dp[x2][j+1],dp[x1][j]+getsum(N-i,i-j+(N-i-1))*3);
            }
        for (int j=1;j<=min(i,E);j++)
            dp[x1][j]=min(dp[x1][j],dp[x1][j-1]);
        for (int j=min(i,E);j>=0;j--)
            if (dp[x1][j]!=biglongint)
            {
                dp[x1][0]=min(dp[x1][0],j*(j+1)/2+dp[x1][j]+2);
                dp[x2][j+1]=min(dp[x2][j+1],dp[x1][j]+getsum(N-i,i-j+(N-i-1))*3);
            }
        dp[x2][0]=min(dp[x2][0],dp[x1][0]+getsum(N-i,N)*3);
    }
    printf("%d\n",dp[x1][0]);

    return 0;
}