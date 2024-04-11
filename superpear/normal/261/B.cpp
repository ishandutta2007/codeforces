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

double f[60][60][60];
double fac[60];
int n,p,a[60];

int main()
{
    fac[0]=1;
    for (int i=1;i<=60;i++) fac[i]=fac[i-1]*i;

    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&p);

    double ans=0,s;

    for (int i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        f[0][0][0]=1;
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
                for (int e=0;e<p;e++)
                {
                    if ((j+1!=i)&&(e+a[j+1]<=p)) f[j+1][k+1][e+a[j+1]]+=(f[j][k][e])*(k+1);
                    f[j+1][k][e]+=f[j][k][e];
                }
        s=0;
        for (int j=0;j<n;j++)
            for (int e=0;e<=p-a[i];e++)
                s+=f[n][j][e]*fac[n-1-j];
        ans+=double(s)/fac[n];
    }
    printf("%.10lf\n",ans);

    return 0;
}