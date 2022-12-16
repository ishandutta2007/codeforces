#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    string s;
    int n,m,up;
    int st[N],top;
    int pos[N];
    typedef pair<int,int> pr;
    vector<pr> col[N];
    vector<int> tt[N];
    int ret[N];
    bool vis[N];
    struct BIT
    {
        int tr[N];
        inline void update(int x,int k)
        {
            for(int i=x;i<=up;i+=lowbit(i)) tr[i]+=k;
        }
        inline int query(int x)
        {
            int sum=0;
            for(int i=x;i>=1;i-=lowbit(i)) sum+=tr[i];
            return sum;
        }
    }T;
    int tl[N],tr[N];
    int trie[N][26];
    int tot;
    struct acam
    {
        int son[N][26],fail[N],sum[N];
        vector<int> eg[N];
        int num=0,idx=0;
        inline void insert(string s,int x,int y)
        {
            int len=s.length(),now=0;
            for(int i=0;i<len;++i)
            {
                int c=s[i]-'a';
                if(!son[now][c]) son[now][c]=++num;
                now=son[now][c];
            }
            pos[x]=now;
            col[y].emplace_back(pr(now,x));
        }
        inline void dfs(int now)
        {
            tl[now]=++idx;
            for(int t:eg[now])
            {
                dfs(t);
            }
            tr[now]=idx;
        }
        inline void getfail()
        {
            queue<int> q;
            for(int i=0;i<26;++i)
            {
                if(son[0][i]) q.push(son[0][i]);
            }
            while(!q.empty())
            {
                int now=q.front();
                q.pop();
                for(int i=0;i<26;++i)
                {
                    if(son[now][i])
                    {
                        fail[son[now][i]]=son[fail[now]][i];
                        //cout<<now<<' '<<son[now][i]<<"!!"<<endl;
                        q.push(son[now][i]);
                    }
                    else son[now][i]=son[fail[now]][i];
                }
            }
            for(int i=1;i<=num;++i) eg[fail[i]].emplace_back(i);
            dfs(0);
        }
        inline void dfs2(int now1,int now2)
        {
            if(now2)
            {
                T.update(tl[now2],1);
                //T.update(tr[now2]+1,-1);
            }
            for(int x:tt[now1])
            {
                for(pr tmp:col[x])
                {
                    // if(tmp.second==11)
                    // {
                    //     cout<<tr[tmp.first]<<' '<<tl[tmp.first]<<'\n';
                    //     cout<<T.query(tr[tmp.first])<<' '<<T.query(tl[tmp.first]-1)<<"!!!"<<'\n';
                    // }
                    ret[tmp.second]=T.query(tr[tmp.first])-T.query(tl[tmp.first]-1);
                }
            }
            for(int i=0;i<26;++i)
            {
                if(trie[now1][i])
                {
                    dfs2(trie[now1][i],son[now2][i]);
                }
            }
            if(now2)
            {
                T.update(tl[now2],-1);
               // T.update(tr[now2]+1,1);
            }
        }
    }ACAM;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int opt,x;char ch;
            cin>>opt;
            int now=0;
            if(opt==2)
            {
                cin>>x;
                now=st[x];
            }
            cin>>ch;
            if(!trie[now][ch-'a']) trie[now][ch-'a']=++tot;
            now=trie[now][ch-'a'];
            st[++top]=now;
            tt[now].emplace_back(i);
        }
        cin>>m;
        for(int i=1;i<=m;++i)
        {
            int x;cin>>x;
            cin>>s;
            ACAM.insert(s,i,x);
        }
        ACAM.getfail();
        up=ACAM.num+5;
        ACAM.dfs2(0,0);
        for(int i=1;i<=m;++i) cout<<ret[i]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
4 3
bbaaa
abaaab
aa
-2
-2
+1
?abaabaaab

*/