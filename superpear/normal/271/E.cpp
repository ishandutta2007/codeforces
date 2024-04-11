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

int a[100005];

int gcd(int a,int b)
{
    if (b==0) return a; else return gcd(b,a%b);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        --a[i];
    }
    int e=a[1];
    for (int i=2;i<=n;i++)
        e=gcd(e,a[i]);

    vector<int> f;
    for (int i=1;i*i<=e;i++)
        if (e%i==0)
        {
            f.p_b(i);
            f.p_b(e/i);
        }
    sort(f.begin(),f.end());
    for (int i=0;i<f.size();i++)
        if (f[i]*2<=m) f.p_b(f[i]*2);
    sort(f.begin(),f.end());
    LL ans=0;
    for (int i=0;i<f.size();i++)
        if ((i==0)||(f[i]!=f[i-1])) ans+=(LL)(m-f[i]);
    cout<<ans<<endl;

    return 0;
}