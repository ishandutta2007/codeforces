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

const int maxn=1000055;

int mulfa[maxn][22],depth[maxn];
int Q,o,lc,rc,ans,cs;

int lca(int x,int y)
{
    if (depth[x]<depth[y]) swap(x,y);
    for (int i=20;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[y]) x=mulfa[x][i];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
        if (mulfa[x][i]!=mulfa[y][i]) x=mulfa[x][i],y=mulfa[y][i];
    return mulfa[x][0];
}

int dist(int x,int y)
{
    return depth[x]+depth[y]-depth[lca(x,y)]*2;
}

int main()
{
    scanf("%d",&Q);
    o=4;
    depth[1]=1;
    depth[2]=depth[3]=depth[4]=2;
    memset(mulfa,0,sizeof(0));
    mulfa[2][0]=mulfa[3][0]=mulfa[4][0]=1;
    lc=2,rc=3;
    ans=2;
    for (int tc=1;tc<=Q;tc++)
    {
        scanf("%d",&cs);
        depth[o+1]=depth[o+2]=depth[cs]+1;
        mulfa[o+1][0]=mulfa[o+2][0]=cs;
        for (int i=1;i<=20;i++)
            mulfa[o+1][i]=mulfa[o+2][i]=mulfa[mulfa[o+1][i-1]][i-1];
        if (dist(o+1,lc)>ans)
        {
            ans=dist(o+1,lc);
            rc=o+1;
        }
        if (dist(o+1,rc)>ans)
        {
            ans=dist(o+1,rc);
            lc=o+1;
        }
        if (dist(o+2,lc)>ans)
        {
            ans=dist(o+2,lc);
            rc=o+2;
        }
        if (dist(o+2,rc)>ans)
        {
            ans=dist(o+2,rc);
            lc=o+2;
        }
        printf("%d\n",ans);
        o+=2;
    }
    return 0;
}