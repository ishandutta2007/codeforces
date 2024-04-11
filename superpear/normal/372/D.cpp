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

vector<int> f[maxn];
int biao[maxn],depth[maxn],mulfa[maxn][18],land[maxn];
set<int> g;
int N,K,o,nowsize,xc,yc,last,ans;

void dfs(int s,int fa)
{
    ++o,biao[o]=s;
    depth[s]=depth[fa]+1;
    mulfa[s][0]=fa;
    for (int i=1;i<=17;i++)
        mulfa[s][i]=mulfa[mulfa[s][i-1]][i-1];
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
            dfs(f[s][i],s);
}

int LCA(int x,int y)
{
    if (depth[x]<depth[y]) swap(x,y);
    for (int i=17;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[y]) x=mulfa[x][i];
    if (x==y) return x;
    for (int i=17;i>=0;i--)
        if (mulfa[x][i]!=mulfa[y][i]) x=mulfa[x][i],y=mulfa[y][i];
    return mulfa[x][0];
}

void eraseit(int s)
{
    int c=land[s];
    set<int>::iterator ck=g.l_b(c),cnext=ck,cpre=ck;
    ++cnext;
    if (cnext==g.end()) cnext=g.begin();
    if (cpre==g.begin()) cpre=g.end();
    --cpre;
    int a1=*cpre,b1=c,c1=*cnext;
    a1=biao[a1],b1=biao[b1],c1=biao[c1];
    nowsize-=(depth[b1]+depth[a1]-depth[LCA(a1,b1)]*2)
            +(depth[b1]+depth[c1]-depth[LCA(b1,c1)]*2)
            -(depth[a1]+depth[c1]-depth[LCA(a1,c1)]*2);
    g.erase(c);
}

void insertit(int s)
{
    int c=land[s];
    g.insert(c);
    set<int>::iterator ck=g.l_b(c),cnext=ck,cpre=ck;
    ++cnext;
    if (cnext==g.end()) cnext=g.begin();
    if (cpre==g.begin()) cpre=g.end();
    --cpre;
    int a1=*cpre,b1=c,c1=*cnext;
    a1=biao[a1],b1=biao[b1],c1=biao[c1];
    nowsize+=(depth[b1]+depth[a1]-depth[LCA(a1,b1)]*2)
            +(depth[b1]+depth[c1]-depth[LCA(b1,c1)]*2)
            -(depth[a1]+depth[c1]-depth[LCA(a1,c1)]*2);
}

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d %d",&N,&K);
    K=(K-1)*2;
    for (int i=1;i<N;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(mulfa,0,sizeof(mulfa));
    memset(depth,0,sizeof(depth));
    o=0;
    dfs(1,0);
    for (int i=1;i<=N;i++) land[biao[i]]=i;
    last=1;
    ans=0;
    nowsize=0;
    g.insert(biao[1]);
    for (int i=1;i<=N;i++)
    {
        if (i!=1) eraseit(i-1);
        while ((last<=N)&&(nowsize<=K))
        {
            //cout<<i<<" "<<last<<" "<<nowsize<<endl;
            ++last;
            if (last>N) break;
            insertit(last);
        }
        if (last<=N) eraseit(last);
        --last;
        ans=max(ans,last-i+1);
    }
    printf("%d\n",ans);

    return 0;
}