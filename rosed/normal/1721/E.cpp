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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        string s;cin>>s;
        int n=s.length();
        vector<int> nxt(n+20);
        vector pre(n+15,vector<int>(26));
        auto getkmp=[&]()
        {
            int t1=0,t2;
            nxt[0]=t2=-1;
            for(int i=0;i<26;++i) pre[0][i]=-1;
            pre[0][s[0]-'a']=0;
            while(t1<n)
            {
                if(t2==-1||s[t1]==s[t2])
                {
                    nxt[++t1]=++t2;
                    for(int i=0;i<26;++i)
                    {
                        pre[t1][i]=pre[t2][i];
                    }
                    if(t1!=n) pre[t1][s[t1]-'a']=t1;
                }
                else t2=pre[t2][s[t1]-'a'];
            }
        };
        getkmp();
        int m;
        cin>>m;
        for(int i=1;i<=m;++i)
        {
            string t;cin>>t;
            int len=t.length();
            for(int j=0;j<len;++j) s+=t[j];
            int t1=n,t2=nxt[n];
            int tmp=pre[n][s[n]-'a'];
            pre[n][s[n]-'a']=n;
            while(t1<n+len)
            {
                if(t2==-1||s[t1]==s[t2])
                {
                    nxt[++t1]=++t2;
                    for(int i=0;i<26;++i)
                    {
                        pre[t1][i]=pre[t2][i];
                    }
                    if(t1!=n+len) pre[t1][s[t1]-'a']=t1;
                }
                else t2=pre[t2][s[t1]-'a'];
            }
            pre[n][s[n]-'a']=tmp;
            for(int j=0;j<len;++j)
            {
                s.pop_back();
                cout<<nxt[n+j+1]<<' ';
            }
            cout<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/