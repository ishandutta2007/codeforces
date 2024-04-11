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

const int bigp=51123987;
int N,o,sc,ans;
int a[205],next[205][5],f[155][55][55][55];
char st[205];

int main()
{
    scanf("%d",&N);
    sc=N/3+1;
    int NB=N;
    scanf("%s",st);
    for (int i=1;i<=N;i++) a[i]=st[i-1]-96;
    o=1;
    for (int i=2;i<=N;i++)
        if (a[i]!=a[i-1]) ++o,a[o]=a[i];
    memset(next,0,sizeof(next));
    for (int i=0;i<=N;i++)
        for (int j=i;j<=N;j++)
        {
            if ((a[j]==1)&&(next[i][1]==0)) next[i][1]=j;
            if ((a[j]==2)&&(next[i][2]==0)) next[i][2]=j;
            if ((a[j]==3)&&(next[i][3]==0)) next[i][3]=j;
        }
    N=o;
    memset(f,0,sizeof(f));
    f[0][0][0][0]=1;
    ans=0;
    for (int i=0;i<=N;i++)
        for (int j=0;j<=sc;j++)
            for (int k=0;k<=sc;k++)
                for (int s=0;s<=sc;s++)
                    if (f[i][j][k][s]!=0)
                    {
                        if (next[i][1]!=0) f[next[i][1]][j+1][k][s]=(f[next[i][1]][j+1][k][s]+f[i][j][k][s])%bigp;
                        if (next[i][2]!=0) f[next[i][2]][j][k+1][s]=(f[next[i][2]][j][k+1][s]+f[i][j][k][s])%bigp;
                        if (next[i][3]!=0) f[next[i][3]][j][k][s+1]=(f[next[i][3]][j][k][s+1]+f[i][j][k][s])%bigp;
                        if ((j+k+s==NB)&&(abs(j-k)<=1)&&(abs(k-s)<=1)&&(abs(j-s)<=1)) ans=(ans+f[i][j][k][s])%bigp;
                    }
    printf("%d\n",ans);

    return 0;
}