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

const int bigp=1000000007;

int N,K,ans;
int a[105];
int dp[105][105][2];

int main()
{
    scanf("%d",&K);
    N=0;
    while (K>0)
    {
        ++N,a[N]=K%2,K/=2;
    }
    for (int i=1;i<=N/2;i++) swap(a[i],a[N+1-i]);

    memset(dp,0,sizeof(dp));
    dp[0][0][1]=1;
    dp[1][0][0]=1;
    for (int i=0;i<N;i++)
        for (int j=0;j<=N;j++)
        {
            if (dp[i][j][0]!=0)
            {
                dp[i+1][j+1][0]=(dp[i+1][j+1][0]+dp[i][j][0])%bigp;
                dp[i+1][j][0]=(dp[i+1][j][0]+(LL)dp[i][j][0]*(1<<j))%bigp;
            }
            if (dp[i][j][1]!=0)
            {
                if (a[i+1]==1) dp[i+1][j+1][1]=(dp[i+1][j+1][1]+dp[i][j][1])%bigp;
                if (j>0)
                {
                    if (a[i+1]==1)
                    {
                        dp[i+1][j][1]=(dp[i+1][j][1]+(LL)dp[i][j][1]*(1<<(j-1)))%bigp;
                        dp[i+1][j][0]=(dp[i+1][j][0]+(LL)dp[i][j][1]*(1<<(j-1)))%bigp;
                    }
                    else
                        dp[i+1][j][1]=(dp[i+1][j][1]+(LL)dp[i][j][1]*(1<<(j-1)))%bigp;
                }
            }
        }
    ans=0;
    for (int i=0;i<=N;i++)
        ans=(ans+dp[N][i][0])%bigp,
        ans=(ans+dp[N][i][1])%bigp;
    printf("%d\n",ans);

    return 0;
}