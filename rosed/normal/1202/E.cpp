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
    const int N=2e5+10,mod=1e9+7,inf=2e9;
    string s,txt;
    int n,m,up,ans;
    struct acam
    {
        int son[N][26],fail[N],str[N];
        int dp[N];
        bool vis[N];
        vector<int> eg[N];
        map<signed,signed> pos[N];
        int num=0;
        inline void insert(string s)
        {
            int len=s.length(),now=0;
            for(int i=0;i<len;++i)
            {
                int c=s[i]-'a';
                if(!son[now][c]) son[now][c]=++num;
                now=son[now][c];
            }
            ++str[now];
        }
        inline void dfs(int now)
        {
            for(int t:eg[now])
            {
                str[t]+=str[now];
                dfs(t);
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
            int now=0,len=s.length();
            for(int i=0;i<len;++i)
            {
                int c=s[i]-'a';
                now=son[now][c];
                //cout<<str[now]<<"!!!!!!!!"<<'\n';   
                dp[i]=str[now];
            }
            //cout<<"---------------\n";
        }
    }A1,A2;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>txt;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>s;
            A1.insert(s);
            reverse(s.begin(),s.end());
            A2.insert(s);
        }
        A1.getfail();
        A2.getfail();
        A1.query(txt);
        reverse(txt.begin(),txt.end());
        A2.query(txt);
        int len=txt.length();
        for(int i=0;i<len-1;++i)
        {
            //cout<<i<<' '<<len-i-2<<'\n';
            //cout<<A1.dp[i]<<' '<<A2.dp[len-i-2]<<"!!"<<endl;
            ans+=A1.dp[i]*A2.dp[len-i-2];
        }
        cout<<ans<<'\n';
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