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

const int maxn=100005;

int M,N,xc,yc,zc,o,cs;
LL nowans,depth[maxn];
int mulfa[maxn][18],lc[maxn],rc[maxn],biao[maxn],d2[maxn];
set<int> g;
set<int>::iterator tf,t1,t2;
char ch;
vector<PII> f[maxn];

void dfs(int s,int father,int last)
{
    ++o;
    mulfa[s][0]=father;
    for (int i=1;i<=17;i++)
        mulfa[s][i]=mulfa[mulfa[s][i-1]][i-1];
    depth[s]=depth[father]+last;
    d2[s]=d2[father]+1;
    lc[s]=o;
    biao[o]=s;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i].w1!=father)
            dfs(f[s][i].w1,s,f[s][i].w2);
    rc[s]=o;
}

int LCA(int x,int y)
{
    if (d2[x]<d2[y]) swap(x,y);
    for (int i=17;i>=0;i--)
        if (d2[mulfa[x][i]]>=d2[y]) x=mulfa[x][i];
    if (x==y) return x;
    for (int i=17;i>=0;i--)
        if (mulfa[x][i]!=mulfa[y][i]) x=mulfa[x][i],y=mulfa[y][i];
    return mulfa[x][0];
}

LL dist(int x,int y)
{
    return depth[x]+depth[y]-depth[LCA(x,y)]*2;
}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<N;i++)
    {
        scanf("%d %d %d",&xc,&yc,&zc);
        f[xc].p_b(m_p(yc,zc));
        f[yc].p_b(m_p(xc,zc));
    }
    o=0;
    memset(biao,0,sizeof(biao));
    memset(lc,0,sizeof(lc));
    memset(rc,0,sizeof(rc));
    memset(mulfa,0,sizeof(mulfa));
    memset(depth,0,sizeof(depth));
    dfs(1,0,0);

    g.clear();
    scanf("%d",&M);
    nowans=0;
    for (int i=1;i<=M;i++)
    {
        while (true)
        {
            scanf("%c",&ch);
            if ((ch=='?')||(ch=='-')||(ch=='+')) break;
        }
        if (ch=='?') printf("%I64d\n",nowans/2); else
        {
            scanf("%d",&cs);
            if (ch=='+')
            {
                g.insert(lc[cs]);
                tf=g.l_b(lc[cs]);
                t1=tf,t2=tf;
                if (t1==g.begin())
                    t1=g.end();
                --t1;
                ++t2;
                if (t2==g.end()) t2=g.begin();
                nowans+=dist(cs,biao[*t1])+dist(cs,biao[*t2])-dist(biao[*t1],biao[*t2]);
            }
            else
            {
                tf=g.l_b(lc[cs]);
                t1=tf,t2=tf;
                if (t1==g.begin())
                    t1=g.end();
                --t1;
                ++t2;
                if (t2==g.end()) t2=g.begin();
                nowans-=dist(cs,biao[*t1])+dist(cs,biao[*t2])-dist(biao[*t1],biao[*t2]);
                g.erase(lc[cs]);
            }
        }
    }

    return 0;
}