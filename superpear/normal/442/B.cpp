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

int N,o;
double a[105],b[105],ans,sm,pc;

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%lf",&a[i]);
    ans=0;
    sort(a+1,a+N+1);
    for (int i=1;i<=N;i++)
    {
        o=0;
        for (int j=N-i+1;j<=N;j++) ++o,b[o]=a[j];
        sm=0;
        for (int j=1;j<=o;j++)
        {
            pc=b[j];
            for (int k=1;k<=o;k++) if (k!=j) pc*=(1-b[k]);
            sm+=pc;
        }
        ans=max(ans,sm);
    }
    printf("%.10lf\n",ans);

    return 0;
}