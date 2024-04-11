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

int m,n,k,cs,flag,rc,fc,tt,ee;
int a[205][205],f[205][205],u[205],use[205];

int main()
{
    cin>>n>>m;
    memset(a,0,sizeof(a));
    ee=1;
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        if (k>0) ee=0;
        for (int j=1;j<=k;j++)
        {
            cin>>cs;
            a[i][cs]=1;
        }
    }
    if (ee==1)
    {
        cout<<n<<endl;
        return 0;
    }
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            flag=1;
            for (int e=1;e<=m;e++)
                if ((a[i][e]==1)&&(a[j][e]==1)) flag=0;
            if (flag==0) f[i][j]=1;
        }
    tt=0;
    memset(use,0,sizeof(use));
    for (int i=1;i<=n;i++)
        if (use[i]==0)
        {
            ++tt;
            use[i]=1;
            rc=1,fc=1,u[rc]=i;
            while (rc<=fc)
            {
                for (int j=1;j<=n;j++)
                    if ((f[u[rc]][j]==1)&&(use[j]==0))
                    {
                        use[j]=1;
                        ++fc,u[fc]=j;
                    }
                ++rc;
            }
        }
    cout<<tt-1<<endl;

    return 0;
}