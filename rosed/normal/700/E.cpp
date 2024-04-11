// LUOGU_RID: 92577204
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
const int inf=1e18;
const int N=6e5+10;
int rt[N];
int n,m;
int ret=0;
struct seg
{
    int tot=1;
    int son[N*20][2],ans[N*20];
    void update(int pos,int l,int r,int &p)
    {
        p=++tot;
        ans[p]=1;
        if(l==r) return;
        if(pos<=mid) update(pos,l,mid,son[p][0]);
        else update(pos,mid+1,r,son[p][1]);
    }
    int merge(int l,int r,int x,int y)
    {
        if(!x||!y) return x|y;
        int p=++tot;
        ans[p]=ans[x]+ans[y];
        son[p][0]=merge(l,mid,son[x][0],son[y][0]);
        son[p][1]=merge(mid+1,r,son[x][1],son[y][1]);
        return p;
    }
    int query(int tl,int tr,int l,int r,int p)
    {
        if(!p) return 0;
        if(tl<=l&&r<=tr) return 1;
        bool ok=0;
        if(tl<=mid) ok|=query(tl,tr,l,mid,son[p][0]);
        if(tr>mid) ok|=query(tl,tr,mid+1,r,son[p][1]);
        return ok;
    }
}T;
struct sam
{
    int tot=1,pre=1;
    int son[N][26],len[N],fa[N];
    vector<int> eg[N];
    int dp[N],minr[N],top[N];
    void insert(int c,int id)
    {
        int p=pre,np=pre=++tot;
        minr[tot]=id;T.update(id,1,n,rt[tot]);
        len[np]=len[p]+1;
        for(;p&&!son[p][c];p=fa[p]) son[p][c]=np;
        if(!p) fa[np]=1;
        else
        {
            int q=son[p][c];
            if(len[q]==len[p]+1) fa[np]=q;
            else
            {
                int nq=++tot;
                for(int i=0;i<26;++i) son[nq][i]=son[q][i];
                fa[nq]=fa[q];len[nq]=len[p]+1;
                fa[np]=fa[q]=nq;minr[nq]=minr[q];
                for(;p&&son[p][c]==q;p=fa[p]) son[p][c]=nq;
            }
        }
    }
    void dfs(int now)
    {
        for(int t:eg[now])
        {
            dfs(t);
            rt[now]=T.merge(1,n,rt[now],rt[t]);
        }
    }
    void dfs2(int now,int topf)
    {
        ret=max(ret,dp[now]);
        for(int t:eg[now])
        {
            dp[t]=dp[now];
            if(now==1||T.query(minr[t]-len[t]+len[topf],minr[t]-1,1,n,rt[topf]))
            {
                ++dp[t];
                dfs2(t,t);
            }
            else dfs2(t,topf);
        }
    }
    void sakura()
    {
        for(int i=2;i<=tot;++i) eg[fa[i]].emplace_back(i);
        dfs(1);
        dfs2(1,1);
    }
}sam;
void solve()
{
    cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;++i)
    {
        sam.insert(s[i]-'a',i+1);
    }
    sam.sakura();
    cout<<ret<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/