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

int m,n,xc,yc;
double f[1005][1005],c1,c2,d1,d2,dw;

int main()
{
    scanf("%d %d",&m,&n);
    scanf("%d %d",&xc,&yc);
    if (n==1)
    {
        cout<<2*(m-xc)<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++) f[m][i]=0;
    for (int i=m-1;i>=xc;i--)
    {
        for (int e=1;e<=100;e++)
        {
            f[i][1]=(f[i+1][1]+f[i][1]+f[i][2])/3+1;
            f[i][n]=(f[i+1][n]+f[i][n]+f[i][n-1])/3+1;
            for (int j=2;j<n;j++)
                f[i][j]=(f[i+1][j]+f[i][j]+f[i][j-1]+f[i][j+1])/4+1;
        }
    }
    printf("%.10lf\n",f[xc][yc]);

    return 0;
}