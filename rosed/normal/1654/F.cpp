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
    const int N=3e5+10,mod=998244353,inv2=5e8+4,inf=2e9;
    inline void main()
    {
        int n,m;cin>>n;
        m=(1<<n);
        string s;cin>>s;
        vector<int> sa(m),rk(m),tmp(m);
        for(int i=0;i<m;++i) sa[i]=i,rk[i]=s[i]-'a';
        sort(sa.begin(),sa.end());
        int k=0;
        auto cmp=[&](int x,int y) -> bool
        {
            return rk[x]==rk[y]?rk[x^k]<rk[y^k]:rk[x]<rk[y];
        };
        for(k=1;k<m;k<<=1)
        {
            sort(sa.begin(),sa.end(),cmp);
            for(int i=0,num=0;i<m;++i)
            {
                if(i==0||cmp(sa[i-1],sa[i])) tmp[sa[i]]=++num;
                else tmp[sa[i]]=num;
            }
            for(int i=0;i<m;++i) rk[i]=tmp[i];
        }
        int ans=sa[0];
        for(int i=0;i<m;++i) cout<<s[i^ans];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::main();
    return 0;
}
/*

*/