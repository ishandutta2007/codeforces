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

double ans[1005][1005];
int m,n;

double search(int m,int n)
{
    if (ans[m][n]!=-1) return ans[m][n];
    if (n==0) return ans[m][n]=1;
    if (m==0) return ans[m][n]=double(1)/(n+1);
    double a=double(1)/(n+1)+double(n)*(1-search(n-1,m))/(n+1);
    double b=double(n)*(1-search(n-1,m))/(n+1);
    double c=1-search(n,m-1);
    double d=1;
    double x=(d-b)/(a-b-c+d);
    return ans[m][n]=x*a+(1-x)*b;
}

int main()
{
    scanf("%d %d",&m,&n);
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=1000;j++)
            ans[i][j]=-1;
    printf("%.10lf %.10lf\n",search(m,n),1-search(m,n));

    return 0;
}