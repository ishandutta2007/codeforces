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

LL n,t,ans;
LL a[50];
LL f[50][50];
int e;

LL getit(LL r,int e)
{
    if (e==-1)
        if (r>=1) return 1;
    if (r<=4)
    {

        int tq=0,t0=0,t1=0;
        if (r>=1) ++tq;
        if (r>=2) ++t0;
        if (r>=3) ++t0;
        if (r>=4) ++t1;
        if (e==-1) return tq; else
        if (e==0) return t0; else
        if (e==1) return t1; else return 0;
    }
    int t;
    for (int i=1;i<=49;i++)
        if (a[i]>=r)
        {
            t=i-1;
            break;
        }
    return f[t][e]+getit(r-a[t],e-1);
}

int main()
{
    a[0]=1;
    for (int i=1;i<=49;i++)
        a[i]=(LL)a[i-1]*2;
    memset(f,0,sizeof(f));
    f[2][0]=2;f[2][1]=1;
    f[3][0]=3;f[3][1]=3;f[3][2]=1;
    for (int i=4;i<=49;i++)
    {
        for (int j=0;j<=49;j++)
            f[i][j]=f[i-1][j]+f[i-1][j-1];
        ++f[i][0];
    }
    cin>>n>>t;
    e=0;
    while (t%2==0)
    {
        e++;
        t/=2;
    }
    if (t!=1)
    {
        cout<<0<<endl;
        return 0;
    }

    ans=getit(n+2,e);
    if (e==0) --ans;
    cout<<ans<<endl;

    return 0;
}