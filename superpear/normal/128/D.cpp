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

const int maxn=100005;

int n,r,a[maxn],f[maxn];

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++)
        if (a[i]-a[i-1]>1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    for (int i=n;i>=1;i--) a[i]-=(a[1]-1);
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++) f[a[i]]++;
    r=a[n];
    for (int i=2;i<r;i++) --f[i];
    for (int i=1;i<r;i++)
    {
        if ((f[i]==0)||(f[i+1]<f[i]))
        {
            cout<<"NO"<<endl;
            return 0;
        }
        f[i+1]-=f[i]-1;
    }
    if (f[r]==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;

    return 0;
}