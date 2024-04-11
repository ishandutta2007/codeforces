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

const int maxn=200;
int n,tk,xc,yc,minc,mink,mm,mg;
int dat[maxn],use[maxn],ans[maxn];
vector<int> a[maxn];
int f[maxn][maxn],dis[maxn][maxn];
vector<PII> g[maxn][maxn];

void dfs(int s,int fa)
{
    int c,flag=1,t1,t2,mm;
    vector<PII> u1,u2;
    for (int i=1;i<=n;i++) f[s][i]=dat[dis[s][i]];
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i];
        if (c!=fa)
        {
            flag=0;
            dfs(c,s);
        }
    }
    for (int j=1;j<=n;j++)
    {
        for (int i=0;i<a[s].size();i++)
        {
            c=a[s][i];
            if (c!=fa)
            {
                t1=f[c][j];
                mm=maxlongint;
                mg=0;
                for (int k=1;k<=n;k++)
                    if (f[c][k]<mm) mm=f[c][k],mg=k;
                t2=mm+tk;
                if (t1<t2)
                {
                    f[s][j]+=t1;
                    g[s][j].p_b(m_p(c,j));
                }
                else
                {
                    f[s][j]+=t2;
                    g[s][j].p_b(m_p(c,mg));
                }
            }
        }

    }
    /*cout<<s<<":";
    for (int i=1;i<=n;i++)
        cout<<f[s][i]<<" ";
    cout<<endl;*/
}

void downall(int s,int e)
{
    use[e]=1;
    for (int i=0;i<g[s][e].size();i++)
        downall(g[s][e][i].first,g[s][e][i].second);
}
int main()
{
    //freopen("E.in","r",stdin);
    cin>>n>>tk;
    dat[0]=0;
    for (int i=1;i<n;i++) cin>>dat[i];
    memset(dis,127,sizeof(dis));
    for (int i=1;i<n;i++)
    {
        cin>>xc>>yc;
        a[xc].p_b(yc);
        a[yc].p_b(xc);
        dis[xc][yc]=1;
        dis[yc][xc]=1;
    }
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if ((dis[i][k]!=biglongint)&&(dis[k][j]!=biglongint))
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    memset(f,127,sizeof(f));
    memset(g,0,sizeof(g));
    dfs(1,0);
    minc=maxlongint;
    mink=0;
    for (int i=1;i<=n;i++)
        if (f[1][i]<minc) minc=f[1][i],mink=i;
    memset(use,0,sizeof(use));
    downall(1,mink);
    for (int i=1;i<=n;i++)
    {
        mm=maxlongint;
        mg=0;
        for (int j=1;j<=n;j++)
            if ((use[j]==1)&&(dis[i][j]<mm)) mm=dis[i][j],mg=j;
        ans[i]=mg;
    }
    cout<<minc+tk<<endl;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;

    return 0;
}