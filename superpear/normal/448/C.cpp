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

int dp[5005][5005];
int N,a[5005];

int main()
{
    //freopen("C.in","r",stdin);
    cin>>N;
    for (int i=1;i<=N;i++) cin>>a[i];
    a[N+1]=0;
    memset(dp,127,sizeof(dp));
    dp[0][0]=0;
    for (int i=0;i<=N;i++)
        for (int j=0;j<=N;j++)
        {
            if (j>a[i]) continue;
            if (j>=a[i+1]) dp[i+1][a[i+1]]=min(dp[i+1][a[i+1]],dp[i][j]);
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            if ((a[i+1]<=N)&&(a[i+1]>=j))
                dp[i+1][a[i+1]]=min(dp[i+1][a[i+1]],dp[i][j]+(a[i+1]-j));
        }
    cout<<dp[N+1][0]<<endl;

    return 0;
}