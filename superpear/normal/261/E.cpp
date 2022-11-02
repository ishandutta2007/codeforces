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

const int prime[26]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int a[30],f[3000005],flag[3000005],g[3000005];
int l,r,p,t,o,k,ans;

void search(int s,int c)
{
    ++o,f[o]=s;
    for (int i=c;i<=t;i++)
        if (r/a[i]>=s) search(s*a[i],i);
}

int main()
{
    cin>>l>>r>>p;
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    t=0;
    for (int i=1;i<=25;i++)
        if (prime[i]<p) ++t,a[t]=prime[i];
    o=0;
    search(1,1);
    sort(f+1,f+o+1);

    memset(g,127,sizeof(g));
    memset(flag,0,sizeof(flag));
    g[1]=0;
    for (int i=2;i<p;i++)
    {
        k=1;
        for (int j=1;j<o;j++)
            if (g[j]!=biglongint)
            {
                while ((k<=o)&&(f[j]*i>f[k])) ++k;
                if (k>o) break;
                g[k]=min(g[k],g[j]+1);
            }
        for (int j=1;j<=o;j++)
            if (g[j]+i<=p) flag[j]=1;
    }
    ans=0;
    for (int i=1;i<=o;i++)
        if ((flag[i]==1)&&(f[i]>=l)) ++ans;
    cout<<ans<<endl;

    return 0;
}