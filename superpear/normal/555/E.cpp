#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143


const int maxn=200005;

int N,M,Q,xc,yc,zc,o,top,tot;
vector<int> F[maxn];
vector<PII> f[maxn];
int where[maxn],dfn[maxn],low[maxn],stack[maxn],mulfa[maxn][18],depth[maxn],up1[maxn],up2[maxn];
map<PII,int> LS;
vector<int> root;
int flag;

void dfs(int s,int fa)
{
    ++o,dfn[s]=o,low[s]=o;
    ++top,stack[top]=s;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i].w2!=fa)
        {
            int cs=f[s][i].w1;
            if (dfn[cs]==0)
            {
                dfs(cs,f[s][i].w2);
                low[s]=min(low[s],low[cs]);
            }
            else
                low[s]=min(low[s],dfn[cs]);
        }
    //cout<<s<<" "<<dfn[s]<<" "<<low[s]<<endl;
    if (dfn[s]==low[s])
    {
        ++tot;
        while (true)
        {
            where[stack[top]]=tot;
            low[stack[top]]=maxlongint;
            if (stack[top]==s) break;
            --top;
        }
        --top;
    }
}

void dfs2(int s,int fa,int deep)
{
    depth[s]=deep;
    mulfa[s][0]=fa;
    for (int i=1;i<=17;i++)
        mulfa[s][i]=mulfa[mulfa[s][i-1]][i-1];
    for (int i=0;i<F[s].size();i++)
        if (F[s][i]!=fa) dfs2(F[s][i],s,deep+1);
}
//remember that all depths should be greater than 0
int LCA(int x,int y)
{
    if (depth[x]<=depth[y]) swap(x,y);
    for (int i=17;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[y]) x=mulfa[x][i];
    if (x==y) return x;
    for (int i=17;i>=0;i--)
        if (mulfa[x][i]!=mulfa[y][i]) x=mulfa[x][i],y=mulfa[y][i];
    return mulfa[x][0];
}

void dfs3(int s,int fa)
{
    for (int i=0;i<F[s].size();i++)
        if (F[s][i]!=fa)
        {
            dfs3(F[s][i],s);
            up1[s]=max(up1[s],up1[F[s][i]]-1);
            up2[s]=max(up2[s],up2[F[s][i]]-1);
        }
    if ((up1[s]>0)&&(up2[s]>0)) flag=0;
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d %d %d",&N,&M,&Q);
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(m_p(yc,i));
        f[yc].p_b(m_p(xc,i));
    }
    o=0;
    memset(where,0,sizeof(where));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    top=0;
    tot=0;
    for (int i=1;i<=N;i++)
        if (dfn[i]==0)
        {
            root.p_b(i);
            dfs(i,0);
        }
    //for (int i=1;i<=N;i++) cout<<where[i]<<" ";cout<<endl;
    for (int i=1;i<=N;i++)
        for (int j=0;j<f[i].size();j++)
            if (where[i]<where[f[i][j].w1])
            {
                PII cs=m_p(where[i],where[f[i][j].w1]);
                if (LS[cs]==0)
                {
                    LS[cs]=1;
                    F[where[i]].p_b(where[f[i][j].w1]);
                    F[where[f[i][j].w1]].p_b(where[i]);
                }
            }
    for (int i=0;i<root.size();i++)
        F[0].p_b(where[root[i]]);

    // Tree stores in F[] rooted 0, with nodes number N (N=previous tot)
    N=tot;
    dfs2(0,0,1);

    flag=1;
    for (int i=1;i<=Q;i++)
    {
        scanf("%d %d",&xc,&yc);
        xc=where[xc],yc=where[yc];
        if (xc==yc) continue;
        zc=LCA(xc,yc);
        if (zc==0) flag=0;
        up1[xc]=depth[xc]-depth[zc];
        up2[yc]=depth[yc]-depth[zc];
    }
    dfs3(0,0);

    if (flag==1) printf("Yes\n"); else printf("No\n");

    return 0;
}