// LUOGU_RID: 92613611
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
struct sam
{
    int tot=1,pre=1;
    int son[N][26],len[N],fa[N];
    vector<int> eg[N];
    int dp[N];
    void init()
    {
        ret=0;
        for(int i=1;i<=tot;++i)
        {
            for(int c=0;c<26;++c) son[i][c]=0;
            len[i]=fa[i]=0;
            eg[i].clear();
            dp[i]=0;
        }
        tot=pre=1;
    }
    void insert(int c,int id)
    {
        int p=pre,np=pre=++tot;
        len[np]=len[p]+1;
        dp[np]=1;
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
            dp[now]+=dp[t];
        }
        if(now!=1) ret+=(len[now]-len[fa[now]])*dp[now]*dp[now];
    }
    void sakura()
    {
        for(int i=2;i<=tot;++i) eg[fa[i]].emplace_back(i);
        dfs(1);
    }
}sam;
void solve()
{
    string s;cin>>s;
    int n=s.length();
    sam.init();
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
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/