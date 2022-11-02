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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

vector<int> f[1005],cs;
vector<PII> a;
double dp[1005][1005];
int now[1005];
int n,m,tt,t,t1,e,k,ct;

double combine(int n,int k)
{
    double s=1;
    for (int i=1;i<=k;i++)
        s*=(double(i)/double(n-i+1));
    return s;
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&tt);
        for (int j=1;j<=tt;j++)
        {
            scanf("%d",&ct);
            f[i].p_b(ct);
            a.p_b(m_p(ct,i));
        }
        sort(f[i].begin(),f[i].end());
    }
    sort(a.begin(),a.end());
    for (int i=0;i<a.size()/2;i++) swap(a[i],a[a.size()-1-i]);
    memset(now,0,sizeof(now));
    t=n-1;
    while ((t>0)&&(a[t].first==a[t-1].first)) --t;
    --t;
    for (int i=0;i<=t;i++) ++now[a[i].second];
    t1=t+1;
    while ((t1+1<a.size())&&(a[t1+1].first==a[t1].first)) ++t1;
    cs.p_b(0);
    int qq[1005];
    memset(qq,0,sizeof(qq));
    for (int i=t+1;i<=t1;i++) cs.p_b(a[i].second),qq[a[i].second]=1;
    e=t1-t;
    k=n-1-t;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for (int i=1;i<=m;i++)
        if (qq[i]==0) dp[0][0]*=combine(f[i].size(),now[i]);
    for (int i=0;i<e;i++)
        for (int j=0;j<=k;j++)
        {
            dp[i+1][j]+=dp[i][j]*combine(f[cs[i+1]].size(),now[cs[i+1]]);
            dp[i+1][j+1]+=dp[i][j]*combine(f[cs[i+1]].size(),now[cs[i+1]]+1);
        }
    //cout<<e<<" "<<k<<endl;
    //cout<<dp[e][k]<<endl;
    printf("%.10lf\n",dp[e][k]*combine(e,k));

    return 0;
}