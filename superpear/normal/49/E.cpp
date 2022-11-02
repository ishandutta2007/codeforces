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

char s1[55],s2[55],sc[55];
int a[55],b[55];
vector<PII> th[55];
int f[55][55][55],g[55][55][55],dp[55][55];
int N,M,K;

int main()
{
    scanf("%s",s1);
    N=strlen(s1);
    for (int i=1;i<=N;i++) a[i]=s1[i-1]-96;
    scanf("%s",s2);
    M=strlen(s2);
    for (int i=1;i<=M;i++) b[i]=s2[i-1]-96;
    scanf("%d",&K);
    for (int i=1;i<=K;i++)
    {
        scanf("%s",sc);
        th[sc[0]-96].p_b(m_p(sc[3]-96,sc[4]-96));
    }
    memset(f,0,sizeof(f));
    for (int i=N;i>=1;i--)
        for (int j=i;j<=N;j++)
            for (int k=1;k<=26;k++)
                if (i==j)
                {
                    if (a[i]==k) f[i][j][k]=1;
                }
                else
                {
                    for (int s=i;s<j;s++)
                    {
                        for (int v=0;v<th[k].size();v++)
                            if ((f[i][s][th[k][v].w1]==1)&&(f[s+1][j][th[k][v].w2]==1))
                            {
                                f[i][j][k]=1;
                                break;
                            }
                        if (f[i][j][k]==1) break;
                    }
                }
    memset(g,0,sizeof(g));
    for (int i=M;i>=1;i--)
        for (int j=i;j<=M;j++)
            for (int k=1;k<=26;k++)
                if (i==j)
                {
                    if (b[i]==k) g[i][j][k]=1;
                }
                else
                {
                    for (int s=i;s<j;s++)
                    {
                        for (int v=0;v<th[k].size();v++)
                            if ((g[i][s][th[k][v].w1]==1)&&(g[s+1][j][th[k][v].w2]==1))
                            {
                                g[i][j][k]=1;
                                break;
                            }
                        if (g[i][j][k]==1) break;
                    }
                }
    memset(dp,127,sizeof(dp));
    dp[0][0]=0;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            if (dp[i][j]!=biglongint)
                for (int xc=i+1;xc<=N;xc++)
                    for (int yc=j+1;yc<=M;yc++)
                        for (int k=1;k<=26;k++)
                            if ((f[i+1][xc][k]==1)&&(g[j+1][yc][k]==1))
                                dp[xc][yc]=min(dp[xc][yc],dp[i][j]+1);
    if (dp[N][M]==biglongint) dp[N][M]=-1;
    printf("%d\n",dp[N][M]);

    return 0;
}