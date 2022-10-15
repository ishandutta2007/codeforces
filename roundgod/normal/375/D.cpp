/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-14 17:12:50
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct query
{
    int l,r,k,id;
}q[MAXN];
int suf[MAXN],a[MAXN],col[MAXN],save[MAXN],ans[MAXN];
int st[MAXN],ed[MAXN],tot;
vector<int> G[MAXN];
int n,m;
const int block=350;
bool cmp(query x,query y)
{
    if(x.l/block!=y.l/block) return x.l/block<y.l/block;
    if (x.l/block&1) return x.r>y.r; else return x.r<y.r;
}
void add(int pos)
{
    int c=col[pos],num=save[c];
    save[c]++;
    suf[num+1]++;
}
void del(int pos)
{
    int c=col[pos],num=save[c];
    assert(num>=1);
    save[c]--;
    assert(suf[num]>=0);
    suf[num]--;
}
void update(int cl,int cr,int l,int r)
{
    while(cl>l) add(--cl);
    while(cr<r) add(++cr);
    while(cl<l) del(cl++);
    while(cr>r) del(cr--);
}
void dfs(int v,int p)
{
    st[v]=++tot;col[st[v]]=a[v];
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
    }
    ed[v]=tot;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    tot=0;
    memset(save,0,sizeof(save));
    memset(suf,0,sizeof(suf));
    for(int i=0;i<m;i++)
    {
        int v,x;
        scanf("%d%d",&v,&x);
        q[i].l=st[v];q[i].r=ed[v];q[i].k=x;q[i].id=i;
    }
    sort(q,q+m,cmp);
    int nowl=2,nowr=1;
    for(int i=0;i<m;i++)
    {
        update(nowl,nowr,q[i].l,q[i].r);
        ans[q[i].id]=suf[q[i].k];
        nowl=q[i].l,nowr=q[i].r;
        assert(nowl>=1&&nowl<=n);
        assert(nowr>=1&&nowr<=n);
    }
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}