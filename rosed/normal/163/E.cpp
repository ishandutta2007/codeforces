#include<bits/stdc++.h>
using namespace std;
namespace red{
//#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    string s[N];
    int n,m,up;
    int pos[N];
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
    struct acam
    {
        int son[N][26],fail[N],sum[N];
        vector<int> eg[N];
        int num=0,tot=0,idx=0;
        inline void insert(string s,int id)
        {
            int len=s.length(),now=0;
            for(int i=0;i<len;++i)
            {
                int c=s[i]-'a';
                if(!son[now][c]) son[now][c]=++num;
                now=son[now][c];
            }
            pos[id]=now;
            ++sum[now];
        }
        inline void dfs(int now)
        {
            tl[now]=++idx;
            for(int t:eg[now])
            {
                dfs(t);
            }
            
            tr[now]=idx;
            if(sum[now])
            {
                T.update(tl[now],sum[now]);
                T.update(tr[now]+1,-sum[now]);
                //cout<<now<<' '<<tl[now]<<' '<<tr[now]<<"!!"<<endl;
            }
            
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
        inline void query(string s)
        {
            int len=s.length(),now=0;
            long long sum=0;
            for(int i=1;i<len;++i)
            {
                int c=s[i]-'a';
                now=son[now][c];
                //cout<<now<<' '<<tl[now]<<' '<<T.query(tl[now])<<"!!"<<'\n';
                sum+=T.query(tl[now]);
            }
            cout<<sum<<'\n';
        }
    }ACAM;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            cin>>s[i];
            ACAM.insert(s[i],i);
            vis[i]=1;
        }
        up=ACAM.num+5;
        ACAM.getfail();
        for(int i=1;i<=n;++i)
        {
            string txt;
            cin>>txt;
            int len=txt.length(),num=0;
            if(txt[0]=='?') ACAM.query(txt);
            if(txt[0]=='-')
            {
                for(int i=1;i<len;++i) num=num*10+txt[i]-'0';
                if(vis[num]==0) continue;
                vis[num]=0;
                T.update(tl[pos[num]],-1);
                T.update(tr[pos[num]]+1,1);
            }
            if(txt[0]=='+')
            {
                for(int i=1;i<len;++i) num=num*10+txt[i]-'0';
                if(vis[num]==1) continue;
                vis[num]=1;
                T.update(tl[pos[num]],1);
                T.update(tr[pos[num]]+1,-1);
            }
        }
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