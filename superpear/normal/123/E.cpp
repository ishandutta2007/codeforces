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

const int maxn=100005;

int n,xc,yc,ostart,oend;
vector<int> a[maxn];
double na,ans;
int startc[maxn],overc[maxn],sum[maxn];
double start[maxn],over[maxn];

void calc(int s,int fa)
{
    int c;
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i];
        if (c!=fa)
        {
            calc(c,s);
            sum[s]+=sum[c]+1;
        }
    }
    na+=over[s]*sum[s];
}

void dfs(int s,int fa,double nowans)
{
    int c;
    double nt;
    //cout<<s<<" "<<nowans<<endl;
    ans+=nowans*start[s];
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i];
        if (c!=fa)
        {
            nt=nowans-(n-1)*over[s]+(n-1)*over[c]-sum[c]*over[c]+(n-2-sum[c])*over[s];
            dfs(c,s,nt);
        }
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        scanf("%d %d",&xc,&yc);
        a[xc].p_b(yc);
        a[yc].p_b(xc);
    }
    ostart=0;oend=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&startc[i],&overc[i]);
        ostart+=startc[i];
        oend+=overc[i];
    }
    for (int i=1;i<=n;i++)
    {
        start[i]=double(startc[i])/ostart;
        over[i]=double(overc[i])/oend;
    }
    memset(sum,0,sizeof(sum));
    na=0;
    calc(1,0);
    ans=0;
    dfs(1,0,na);
    printf("%.15lf\n",n-1-ans);

    return 0;
}