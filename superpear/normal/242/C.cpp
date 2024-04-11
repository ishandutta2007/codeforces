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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int n,xx,yy,xc,yc,xd,yd,rc,ai,bi,fc,vi[10],vj[10];
PII u[200000];

int main()
{
    scanf("%d %d %d %d",&xc,&yc,&xd,&yd);
    map<PII,int> f;
    map<PII,int>::iterator g,t;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&rc,&ai,&bi);
        for (int j=ai;j<=bi;j++) f.insert(make_pair(make_pair(rc,j),maxlongint));
    }
    vi[1]=-1;vj[1]=-1;
    vi[2]=-1;vj[2]=0;
    vi[3]=-1;vj[3]=1;
    vi[4]=0;vj[4]=-1;
    vi[5]=0;vj[5]=1;
    vi[6]=1;vj[6]=-1;
    vi[7]=1;vj[7]=0;
    vi[8]=1;vj[8]=1;
    rc=1;fc=1;u[rc]=make_pair(xc,yc);
    g=f.find(u[rc]);
    g->second=0;
    while (rc<=fc)
    {
        g=f.find(u[rc]);
        for (int i=1;i<=8;i++)
        {
            xx=u[rc].first+vi[i];
            yy=u[rc].second+vj[i];
            t=f.find(make_pair(xx,yy));
            if (t!=f.end())
            {
                if (g->second+1<t->second)
                {
                    ++fc;u[fc]=t->first;
                    t->second=g->second+1;
                }
            }
        }
        if ((f.find(make_pair(xd,yd))->second)!=maxlongint) break;
        g=f.find(u[rc]);
        f.erase(g);
        ++rc;
    }
    if (f.find(make_pair(xd,yd))->second==maxlongint) cout<<-1<<endl; else cout<<(f.find(make_pair(xd,yd))->second)<<endl;

    return 0;
}