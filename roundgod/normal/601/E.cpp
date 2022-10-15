#include<bits/stdc++.h>
#define MAXN 5005
#define MAXK 1005
#define MAXQ 40005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,q;
const int modp=10000000+19;
const int modq=1000000000+7;
int v[MAXQ],w[MAXQ];
int st[MAXQ],ed[MAXQ];
bool ask[MAXQ];
int ans[MAXQ];
vector<P> items[4*MAXQ];
vector<vector<int> > knapsack;
int get_ans(vector<int> &v)
{
    int s=0;
    for(int i=k;i>=1;i--) s=(1LL*s*modp+v[i])%modq;
    return s;
}
vector<int> calc(vector<int> &v,int nv,int nw)
{
    vector<int> tmp(k+1);
    for(int i=0;i<=k;i++)
    {
        tmp[i]=v[i];
        if(i>=nw) tmp[i]=max(tmp[i],v[i-nw]+nv);
    }
    return tmp;
}
void undo()
{
    knapsack.pop_back();
}
void add_item(int k,int l,int r,int x,int y,int u,int v)
{
    if(x>r||l>y) return;
    if(l>=x&&r<=y)
    {
        items[k].push_back(P(u,v));
        return;
    }
    int mid=(l+r)/2;
    add_item(k*2,l,mid,x,y,u,v);add_item(k*2+1,mid+1,r,x,y,u,v);
}
void solve(int k,int l,int r)
{
    if(l>r) return;
    for(auto p:items[k]) knapsack.push_back(calc(knapsack.back(),p.F,p.S));
    if(l==r)
    {
        if(ask[l]) ans[l]=get_ans(knapsack.back());
        for(auto p:items[k]) undo();
        return;
    }
    int mid=(l+r)/2;
    solve(k*2,l,mid);solve(k*2+1,mid+1,r);
    //printf("cnt %d %d %d\n",l,r,cnt);
    for(auto p:items[k]) undo();
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&v[i],&w[i]);
        st[i]=1;
    }
    int tot=n;
    memset(ask,false,sizeof(ask));
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==3)
        {
            ask[i]=true;
            continue;
        }
        if(type==1) 
        {
            ++tot;
            scanf("%d%d",&v[tot],&w[tot]);
            st[tot]=i;
        }
        else
        {
            int x;
            scanf("%d",&x);
            ed[x]=i;
        }
    }
    for(int i=1;i<=tot;i++) add_item(1,1,q,st[i],ed[i]?ed[i]:q,v[i],w[i]);
    knapsack.clear();
    vector<int> tmp(k+1,0);
    knapsack.push_back(tmp);
    solve(1,1,q);
    for(int i=1;i<=q;i++) if(ask[i]) printf("%d\n",ans[i]);
    return 0;
}