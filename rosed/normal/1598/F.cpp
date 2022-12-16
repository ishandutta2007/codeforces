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
    const int N=1e6+10,mod=998244353,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        typedef array<int,2> pr;
        vector<pr> a(n);
        vector<vector<int> > q(n);
        for(int i=0;i<n;++i)
        {
            string s;cin>>s;
            int len=s.length();
            int sum=0;
            q[i].resize(400010,0);
            for(int j=0;j<len;++j)
            {
                if(s[j]=='(') ++sum;
                else --sum;
                a[i][0]=min(a[i][0],sum);
                if(a[i][0]==sum) ++q[i][-sum];
            }
            a[i][1]=sum;
        }
        int S=(1<<n);
        vector<int> dp(S,-inf);
        dp[0]=0;
        vector<int> pre(S);
        int ans=0;
        for(int s=1;s<S;++s)
        {
            for(int k=0;k<n;++k) if((s>>k)&1)
            {
                pre[s]+=a[k][1];
            }
        }
        for(int s=1;s<S;++s)
        {
            for(int k=0;k<n;++k) if((s>>k)&1)
            {
                int sub=s^(1<<k);
                if(pre[sub]<0) continue;
                int tmp=dp[sub]+q[k][pre[sub]];
                ans=max(ans,tmp);
                if(pre[sub]+a[k][0]>=0)
                {
                    dp[s]=max(dp[s],tmp);
                }
            }
        }
        cout<<ans<<'\n';
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
1 7 5 6 8 2 6 5

0 8 5 6 8 0 8 5
3
5 6 5
3 8 5
2
3
8
*/