// LUOGU_RID: 92364965
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
const int N=5e5+10;
int n;
int rt[N];
string t;
int lent;
vector<int> ret;
struct seg
{
    int tot=0;
    int ans[N*20],son[N*20][2];
    void update(int pos,int l,int r,int &p)
    {
        p=++tot;
        ++ans[p];
        if(l==r) return;
        if(pos<=mid) update(pos,l,mid,son[p][0]);
        else update(pos,mid+1,r,son[p][1]);
    }
    int merge(int l,int r,int x,int y)
    {
        if(!x||!y) return x|y;
        int p=++tot;
        if(l==r) return p;
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
struct SAM
{
    int tot=1,pre=1;
    int son[N][26],len[N],fa[N],f[N];
    vector<int> eg[N];
    void insert(int c,int id)
    {
        int p=pre,np=pre=++tot;f[tot]=1;
        len[np]=len[p]+1;
        T.update(id,1,n,rt[np]);
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
                fa[nq]=fa[q],len[nq]=len[p]+1;
                fa[np]=fa[q]=nq;
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
    void sakura()
    {
        for(int i=2;i<=tot;++i) eg[fa[i]].emplace_back(i);
            dfs(1);
    }
    bool check(int l,int r,int pos,int p)
    {
        int c;
        if(pos>=lent) c=-1;
        else c=t[pos]-'a';
        if(c>=0&&son[p][c]&&T.query(l+pos,r,1,n,rt[son[p][c]])&&check(l,r,pos+1,son[p][c]))
        {
            ret.emplace_back(c);return 1;
        }
        for(int i=c+1;i<26;++i)
        {
            if(son[p][i]&&T.query(l+pos,r,1,n,rt[son[p][i]]))
            {
                ret.emplace_back(i);return 1;
            }
        }
        return 0;
    }
}sam;
void solve()
{
    string s;
    cin>>s;
    n=s.length();
    s="#"+s;
    for(int i=1;i<=n;++i)
    {
        sam.insert(s[i]-'a',i);
    }
    sam.sakura();
    int m;
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        int l,r;
        cin>>l>>r>>t;
        lent=t.length();
        ret.clear();
        if(sam.check(l,r,0,1))
        {
            while(!ret.empty())
            {
                cout<<(char)(ret.back()+'a');
                ret.pop_back();
            }
            cout<<'\n';
        }
        else cout<<"-1\n";
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