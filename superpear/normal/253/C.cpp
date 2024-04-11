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

int n;
int a[1000];
int dis[101][100001];
int u[10000001],v[10000001];

bool ok(int x,int y)
{
    if ((x>0)&&(x<=n)&&(y>0)&&(y<=a[x])) return true; else return false;
}
int main()
{
    int x1,y1,x2,y2,xc,yc,rc,fc;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],++a[i];
    cin>>x1>>y1>>x2>>y2;
    memset(dis,127,sizeof(dis));
    dis[x1][y1]=0;
    rc=1;fc=1;u[rc]=x1;v[rc]=y1;
    while (rc<=fc)
    {
        xc=u[rc];yc=v[rc]-1;
        if (ok(xc,yc))
            if (dis[u[rc]][v[rc]]+1<dis[xc][yc])
            {
                dis[xc][yc]=dis[u[rc]][v[rc]]+1;
                ++fc;u[fc]=xc;v[fc]=yc;
            }
        xc=u[rc];yc=v[rc]+1;
        if (ok(xc,yc))
            if (dis[u[rc]][v[rc]]+1<dis[xc][yc])
            {
                dis[xc][yc]=dis[u[rc]][v[rc]]+1;
                ++fc;u[fc]=xc;v[fc]=yc;
            }
        xc=u[rc]-1;
        if (xc>0)
        {
            yc=min(v[rc],a[xc]);
            if (dis[u[rc]][v[rc]]+1<dis[xc][yc])
            {
                dis[xc][yc]=dis[u[rc]][v[rc]]+1;
                ++fc;u[fc]=xc;v[fc]=yc;
            }
        }
        xc=u[rc]+1;
        if (xc<=n)
        {
            yc=min(v[rc],a[xc]);
            if (dis[u[rc]][v[rc]]+1<dis[xc][yc])
            {
                dis[xc][yc]=dis[u[rc]][v[rc]]+1;
                ++fc;u[fc]=xc;v[fc]=yc;
            }
        }
        ++rc;
    }
    cout<<dis[x2][y2]<<endl;

    return 0;
}