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

int n,m,k,xc,yc,ans;
int b[20][20],use[1024][1024],f[1024][1024];

int bitcount(int s)
{
    int e=0;
    while (s>0)
    {
        ++e,s-=s&(-s);
    }
    return e;
}

int search(int s,int t)
{
    if ((s|t)!=s) return f[s][t]=0;
    if ((t==0)||(bitcount(t)==1)) return f[s][t]=0;
    if (use[s][t]!=biglongint) return f[s][t];
    use[s][t]=0;
    if (bitcount(s)==2)
    {
        if (s==t)
        {
            int fc1=0,fc2=0;
            for (int i=1;i<=n;i++)
                if ((t>>(i-1))%2==1)
                    if (fc1==0) fc1=i; else fc2=i;
            if (b[fc1][fc2]==1) return f[s][t]=1; else return f[s][t]=0;
        }
        else return f[s][t]=0;
    }
    int fc=0;
    for (int i=1;i<=n;i++)
        if ((t>>(i-1))%2==1) {fc=i;break;}
    for (int i=1;i<=n;i++)
        if (((s>>(i-1))%2==1)&&((t>>(i-1))%2==0)&&(b[fc][i]==1))
            f[s][t]+=search(s-(1<<(fc-1)),t-(1<<(fc-1)))+search(s-(1<<(fc-1)),t+(1<<(i-1))-(1<<(fc-1)));
    return f[s][t];
}

int main()
{
    cin>>n>>m>>k;
    memset(b,0,sizeof(b));
    for (int i=1;i<=m;i++)
    {
        cin>>xc>>yc;
        b[xc][yc]=1,b[yc][xc]=1;
    }
    memset(f,0,sizeof(f));
    memset(use,127,sizeof(use));
    ans=0;
    for (int i=0;i<(1<<n);i++)
        if (bitcount(i)==k) ans+=search((1<<n)-1,i);
    cout<<ans<<endl;

    return 0;
}