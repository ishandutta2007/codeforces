// LUOGU_RID: 92611460
#include<bits/stdc++.h>
using namespace std;
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
const int inf=1e18;
const int N=1e6+2e5+10;
int rt[N];
int n,m;
int ret=0;
typedef pair<int,int> pr;
struct seg
{
    int tot=1;
    int son[N*10][2];
    pr ans[N*10];
    void update(int pos,int l,int r,int &p)
    {
        if(!p) p=++tot;
        if(l==r)
        {
            ++ans[p].first;
            ans[p].second=l;
            return;
        }
        if(pos<=mid) update(pos,l,mid,son[p][0]);
        else update(pos,mid+1,r,son[p][1]);
        if(ans[son[p][0]].first>=ans[son[p][1]].first) ans[p]=ans[son[p][0]];
        else ans[p]=ans[son[p][1]];
    }
    int merge(int l,int r,int x,int y)
    {
        if(!x||!y) return x|y;
        int p=++tot;
        // cout<<l<<' '<<r<<"!!"<<endl;
        if(l==r)
        {
            ans[p].first=ans[x].first+ans[y].first;
            ans[p].second=l;
            return p;
        }
        son[p][0]=merge(l,mid,son[x][0],son[y][0]);
        son[p][1]=merge(mid+1,r,son[x][1],son[y][1]);
        if(ans[son[p][0]].first>=ans[son[p][1]].first) ans[p]=ans[son[p][0]];
        else ans[p]=ans[son[p][1]];
        return p;
    }
    pr query(int tl,int tr,int l,int r,int p)
    {
        if(!p) return pr{0,tl};
        if(tl<=l&&r<=tr) return ans[p];
        if(tr<=mid) return query(tl,tr,l,mid,son[p][0]);
        if(tl>mid) return query(tl,tr,mid+1,r,son[p][1]);
        pr t1=query(tl,tr,l,mid,son[p][0]),t2=query(tl,tr,mid+1,r,son[p][1]);
        if(t1.first>=t2.first) return t1;
        return t2;
    }
}T;
struct sam
{
    int tot=1,pre=1;
    int son[N][26],len[N],fa[N];
    vector<int> eg[N];
    int pos[N];
    int f[N][21];
    int insert(int pre,int c,int id,bool ok)
    {
        if(son[pre][c]&&len[pre]+1==len[son[pre][c]])
        {
            if(ok) T.update(id,1,n,rt[son[pre][c]]);
            else pos[id]=son[pre][c];
            return son[pre][c];
        }
        int p=pre,np=++tot,nq,flag=0;
        len[np]=len[p]+1;
        if(ok) T.update(id,1,n,rt[tot]);
        else pos[id]=tot;
        for(;p&&!son[p][c];p=fa[p]) son[p][c]=np;
        if(!p) fa[np]=1;
        else
        {
            int q=son[p][c];
            if(len[q]==len[p]+1) fa[np]=q;
            else
            {
                if(p==pre) flag=1;
                nq=++tot;
                for(int c=0;c<26;++c) son[nq][c]=son[q][c];
                fa[nq]=fa[q];len[nq]=len[p]+1;
                fa[q]=fa[np]=nq;
                for(;p&&son[p][c]==q;p=fa[p]) son[p][c]=nq;
            }
        }
        return flag?nq:np;
    }
    void dfs(int now)
    {
        for(int t:eg[now])
        {
            dfs(t);
            rt[now]=T.merge(1,n,rt[now],rt[t]);
        }
    }
    void sakura()
    {
        for(int i=2;i<=tot;++i) eg[fa[i]].emplace_back(i),f[i][0]=fa[i];
        for(int k=1;k<=20;++k)
        {
            for(int i=1;i<=tot;++i)
            {
                f[i][k]=f[f[i][k-1]][k-1];
            }
        }
        dfs(1);
    }
}sam;
void solve()
{
    string s;cin>>s;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string txt;cin>>txt;
        int pre=1;
        for(auto ch:txt)
        {
            int c=ch-'a';
            pre=sam.insert(pre,c,i,1);
        }
    }
    int pre=1,pos=0;
    for(auto ch:s)
    {
        int c=ch-'a';
        pre=sam.insert(pre,c,++pos,0);
    }
    sam.sakura();
    int q;cin>>q;
    while(q--)
    {
        int tl,tr,l,r;
        cin>>tl>>tr>>l>>r;
        int now=sam.pos[r];
        for(int k=20;~k;--k) if(sam.f[now][k]&&sam.len[sam.f[now][k]]>=r-l+1)
        {
            now=sam.f[now][k];
        }
        auto tmp=T.query(tl,tr,1,n,rt[now]);
        cout<<tmp.second<<' '<<tmp.first<<'\n';
    }
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