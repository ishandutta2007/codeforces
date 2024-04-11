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

int M,N;
int a[1005][1005],f[1005][1005],b[1005];

bool ok(int nows)
{
    memset(f,0,sizeof(f));
    int o;
    for (int i=1;i<=M;i++)
    {
        o=0;
        for (int j=1;j<=N;j++)
            if (a[i][j]>=nows) ++o,b[o]=j;
        for (int j=1;j<=o;j++)
            for (int k=j+1;k<=o;k++)
            {
                ++f[b[j]][b[k]];
                if (f[b[j]][b[k]]>1) return true;
            }
    }

    return false;
}

int main()
{
    scanf("%d %d",&M,&N);
    for (int i=1;i<=M;i++)
        for (int j=1;j<=N;j++)
            scanf("%d",&a[i][j]);
    int left=0,right=maxlongint/2,mid;
    while (left<=right)
    {
        mid=(left+right)/2;
        if (ok(mid)) left=mid+1; else right=mid-1;
    }
    printf("%d\n",right);

    return 0;
}