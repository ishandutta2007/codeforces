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

int N,M,xc,yc,s1,s2,ans,flag;
int dp[305][305][10];
int fc[305][305],fg[305][305];

int main()
{
    scanf("%d %d",&N,&M);
    memset(dp,127,sizeof(dp));
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d %d %d",&xc,&yc,&s1,&s2);
        dp[xc][yc][0]=-s1;
        dp[yc][xc][0]=-s2;
    }
    for (int i=1;i<=N;i++)
        dp[i][i][0]=0;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=N;j++)
            for (int k=1;k<=N;k++)
                for (int p=1;p<=N;p++)
                    if ((dp[j][p][i-1]!=biglongint)&&(dp[p][k][i-1]!=biglongint))
                        dp[j][k][i]=min(dp[j][k][i],dp[j][p][i-1]+dp[p][k][i-1]);
    ans=0;
    memset(fc,127,sizeof(fc));
    for (int i=1;i<=N;i++) fc[i][i]=0;
    for (int i=9;i>=0;i--)
    {
        memset(fg,127,sizeof(fg));
        for (int j=1;j<=N;j++)
            for (int k=1;k<=N;k++)
                for (int p=1;p<=N;p++)
                    if ((fc[j][k]!=biglongint)&&(dp[k][p][i]!=biglongint))
                        fg[j][p]=min(fg[j][p],fc[j][k]+dp[k][p][i]);
        flag=1;
        for (int j=1;j<=N;j++)
            if (fg[j][j]<0)
            {
                flag=0;
                break;
            }
        if (flag==1)
        {
            ans+=(1<<i);
            for (int j=1;j<=N;j++)
                for (int k=1;k<=N;k++)
                    fc[j][k]=fg[j][k];
        }
    }
    if (ans>N) ans=-1;
    printf("%d\n",ans+1);

    return 0;
}