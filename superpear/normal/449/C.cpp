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

int N,o,cc;
vector<PII> ans;
int p[1000005],use[1000005],a[1000005];

bool prime(int s)
{
    for (int i=2;i*i<=s;i++)
        if (s%i==0) return false;
    return true;
}

int main()
{
    scanf("%d",&N);
    o=0;
    for (int i=2;i<=N;i++)
    {
        if (prime(i)) ++o,p[o]=i;
    }
    memset(use,0,sizeof(use));
    for (int i=2;i<=o;i++)
    {
        cc=0;
        for (int j=1;j<=N/p[i];j++)
            if (use[p[i]*j]==0)
            {
                use[p[i]*j]=1;
                ++cc,a[cc]=j;
            }
        if (cc%2==1)
        {
            use[p[i]*2]=0;
            for (int j=2;j<cc;j++) a[j]=a[j+1];
            --cc;
        }
        for (int j=1;j<=cc/2;j++)
            ans.p_b(m_p(p[i]*a[j*2-1],p[i]*a[j*2]));
    }
    cc=0;
    for (int i=1;i<=N;i++)
        if (i%2==0)
            if (use[i]==0) ++cc,a[cc]=i;
    for (int j=1;j<=cc/2;j++)
        ans.p_b(m_p(a[j*2-1],a[j*2]));
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].w1,ans[i].w2);

    return 0;
}