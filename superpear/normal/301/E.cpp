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

int C[205][205],f[105][2][105][105];
int N,M,K,kc,ans,s1,s2;

int main()
{
    C[0][0]=1;
    for (int i=1;i<=200;i++)
    {
        C[i][0]=1;
        for (int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%bigp;
    }
    scanf("%d %d %d",&N,&M,&K);
    ++N;
    memset(f,0,sizeof(f));
    for (int i=1;i<=N;i++)
        f[i][1][1][i-1]=1;
    ans=0;
    for (int j=1;j<=M;j++)
    {
        s1=j%2,s2=1-j%2;
        for (int i=2;i<=N;i++)
            for (int k=1;k<=K;k++)
                ans=(ans+(LL)f[i][s1][k][0]*(M-j+1))%bigp;
        if (j==M) break;
        for (int i=0;i<=N;i++)
            for (int k=0;k<=K;k++)
                for (int s=0;s<=N;s++)
                    f[i][s2][k][s]=0;
        for (int i=1;i<N;i++)
            for (int k=1;k<=K;k++)
                for (int s=0;s<=N;s++)
                    if (f[i][s1][k][s]!=0)
                        for (int e=s;e<=N-i;e++)
                        {
                            if (C[e-1][s-1]>K) continue;
                            kc=k*C[e-1][s-1];
                            if (kc<=K)
                                f[i+e][s2][kc][e-s]=(f[i+e][s2][kc][e-s]+f[i][s1][k][s])%bigp;
                        }
    }
    printf("%d\n",ans);

    return 0;
}