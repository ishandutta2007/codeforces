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

vector<PII> f[maxn];
vector<int> k[maxn];
int size[maxn],sum[maxn],ding[maxn],vis[maxn];
int n,xc,yc,zc;
LL nt,ttime;

void dfs(int s,int fa)
{
    int c;
    size[s]=1;
    for (int i=0;i<f[s].size();i++)
    {
        c=f[s][i].first;
        if (c!=fa)
        {
            dfs(c,s);
            ding[c]=f[s][i].second*2;
            size[s]+=size[c];
            sum[s]+=sum[c]+f[s][i].second*2;
        }
    }
}

bool cmp(int a,int b)
{
    return (LL)(sum[a]+ding[a])*size[b]<(LL)(sum[b]+ding[b])*size[a];
}

void mark(int s,int fa)
{
    int c;
    for (int i=0;i<f[s].size();i++)
    {
        c=f[s][i].first;
        if (c!=fa)
        {
            mark(c,s);
            k[s].p_b(c);
        }
    }
    sort(k[s].begin(),k[s].end(),cmp);
}

void visall(int s,int fa)
{
    int c;
    vis[s]=nt;
    for (int i=0;i<k[s].size();i++)
    {
        nt+=(LL)ding[k[s][i]]/2;
        visall(k[s][i],s);
        nt+=(LL)ding[k[s][i]]/2;
    }
}

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        scanf("%d %d %d",&xc,&yc,&zc);
        f[xc].p_b(m_p(yc,zc));
        f[yc].p_b(m_p(xc,zc));
    }
    memset(sum,0,sizeof(sum));
    memset(size,0,sizeof(size));
    dfs(1,0);
    mark(1,0);
    nt=0;
    memset(vis,0,sizeof(vis));
    ttime=0;
    visall(1,0);
    for (int i=1;i<=n;i++) ttime+=(LL)vis[i];
    printf("%.10lf\n",double(ttime)/(n-1));

    return 0;
}