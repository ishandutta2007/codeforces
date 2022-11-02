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


LL X,K;
int o,e;
LL ans[100005],a[100005];
map<LL,int> kk;
map<LL,int>::iterator cc;
vector<LL> f[1000005];

void dfs(int e,LL K)
{
    if (e==1)
    {
        ++o;
        ans[o]=a[e];
        return;
    }
    if (K==0)
    {
        ++o;
        ans[o]=a[e];
        return;
    }
    if (f[e].size()==0)
    {
        for (int i=1;i<=e;i++)
            if (a[e]%a[i]==0) f[e].p_b(i);
    }
    for (int i=0;i<f[e].size();i++)
    {
        dfs(f[e][i],K-1);
        if (o==100000) break;
    }
}

int main()
{
    cin>>X>>K;
    e=0;
    for (int i=1;(LL)i*i<=X;i++)
        if (X%i==0)
        {
            ++e,a[e]=i;
            if ((LL)i*i!=X) ++e,a[e]=X/i;
        }
    sort(a+1,a+e+1);

    if (K>100000) K=100000;
    o=0;
    dfs(e,K);
    for (int i=1;i<o;i++) printf("%I64d ",ans[i]);printf("%I64d\n",ans[o]);

    return 0;
}