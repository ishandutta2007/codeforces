#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        string s;cin>>s;
        vector<int> q(26,-1);
        vector<bool> vis(26,0);
        vector<int> nxt(26,-1),pre(26,-1);
        auto check=[&](int x,int y,int id) -> bool
        {
            int num=0;
            while(x!=-1&&++num<26)
            {
                if(x==y) return 1;
                x=pre[x];
            }
            return 0;
        }; 
        for(int i=0;i<n;++i)
        {
            int c=s[i]-'a';
            if(q[c]!=-1) continue;
            for(int k=0;k<26;++k)
            {
                if(vis[k]||k==c) continue;
                if(check(k,c,i)) continue;
                vis[k]=1;
                q[c]=k;
                nxt[k]=c;
                pre[c]=k;
                break;
            }
        }
        for(int i=0;i<n;++i)
        {
            int c=s[i]-'a';
            cout<<(char)(q[c]+'a');
        }
        cout<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
1 n/2 -> (1,n/2),(1,n/2+1)
3,n/2+1 -> (1,n/2-1),(1,n/2+2);
3,n-3 -> (1,n-6)
4,n-4 -> (1,n-3)

*/