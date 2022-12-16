#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        string s,t;
        cin>>s>>t;
        int n=s.length(),m=t.length();
        vector dp(n,vector<int>(26,-1));
        vector<int> st(26,-1);
        for(int i=n-1;i>=0;--i)
        {
            st[s[i]-'a']=i;
            if(i!=n-1)
            {
                dp[i]=dp[i+1];
                dp[i][s[i+1]-'a']=i+1;
            }
        }
        int sum=0,now=-1;
        for(int i=0;i<m;++i)
        {
            int c=t[i]-'a';
            if(now==-1||dp[now][c]==-1)
            {
                ++sum;
                now=st[c];
                if(now==-1)
                {
                    cout<<"-1\n";
                    return;
                }
            }
            else now=dp[now][c];
        }
        cout<<sum<<'\n';
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

*/