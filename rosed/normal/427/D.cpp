// LUOGU_RID: 92636597
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
int rt[N];
int n,m;
int ret=inf;
struct sam
{
    int tot=1,pre=1;
    int son[N][26],len[N],fa[N];
    vector<int> eg[N];
    int dp[N][2];
    int insert(int pre,int c,int id)
    {
        if(son[pre][c]&&len[pre]+1==len[son[pre][c]])
        {
            ++dp[son[pre][c]][id];
            return son[pre][c];
        }
        int p=pre,np=++tot,nq,flag=0;
        len[np]=len[p]+1;
        ++dp[tot][id];
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
            // cout<<now<<' '<<t<<"!!"<<endl;
            dfs(t);
            dp[now][0]+=dp[t][0];
            dp[now][1]+=dp[t][1];
        }
        if(dp[now][0]==1&&dp[now][1]==1&&now!=1)
            ret=min(ret,len[fa[now]]+1);
    }
    void sakura()
    {
        for(int i=2;i<=tot;++i) eg[fa[i]].emplace_back(i);
        dfs(1);
    }
}sam;
void solve()
{
    string s,t;
    cin>>s>>t;
    n=s.length(),m=t.length();
    int pre=1;
    for(int i=0;i<n;++i) pre=sam.insert(pre,s[i]-'a',1);
    pre=1;
    for(int i=0;i<m;++i) pre=sam.insert(pre,t[i]-'a',0);
    sam.sakura();
    if(ret==inf) ret=-1;
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