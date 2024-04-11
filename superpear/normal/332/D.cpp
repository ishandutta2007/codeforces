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

int N,K;
int a[2003][2005],b[2004][2002];

int main()
{
    scanf("%d %d",&N,&K);
    for (int i=1;i<=N;i++)
        for (int j=i+1;j<=N;j++)
            scanf("%d",&a[i][j]),a[j][i]=a[i][j];
    if (K!=2)
    {
        LL e=0;
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if (a[i][j]!=-1) e+=a[i][j];
        printf("%I64d\n",(LL)(trunc(e/N)));
    }
    else
    {
        LL e=0,o=0;
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if ((i!=j)&&(a[i][j]!=-1)) ++b[i][0],b[i][b[i][0]]=j;
        for (int i=1;i<=N;i++)
            for (int j=1;j<=b[i][0];j++)
                for (int k=j+1;k<=b[i][0];k++)
                    ++o,e+=a[i][b[i][j]]+a[i][b[i][k]];
        printf("%I64d\n",(LL)(trunc(e/o)));
    }

    return 0;
}