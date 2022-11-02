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

int N,S,sk,Cs,Cp;
int x[105],y[105],C[1505][1505];
int dp[105][1005];

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d",&x[i]);
    for (int i=1;i<=N;i++) scanf("%d",&y[i]);
    S=0;
    for (int i=1;i<=N;i++) S+=x[i];
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for (int i=1;i<=S+500;i++)
    {
        C[i][0]=1;
        for (int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%bigp;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    sk=S;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<=S;j++)
            if (dp[i][j]!=0)
            {
                Cs=(LL)dp[i][j]*C[sk][x[i+1]]%bigp;
                for (int ss=0;ss<=min(y[i+1],j+x[i+1]);ss++)
                {
                    Cp=(LL)Cs*C[j+x[i+1]][ss]%bigp;
                    dp[i+1][j+x[i+1]-ss]+=Cp,
                    dp[i+1][j+x[i+1]-ss]%=bigp;
                }
            }
        sk-=x[i+1];
    }
    printf("%d\n",dp[N][0]);

    return 0;
}