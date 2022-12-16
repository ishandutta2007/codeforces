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
        int n,m;
        cin>>n;
        typedef array<int,2> pr;
        int maxn=3000000;
        vector<int> cnt(maxn+5);
        vector<int> suf(maxn+5);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int x;cin>>x;
            ++cnt[x];
            if(x*x<=maxn) --suf[x*x];
            else --ans;
        }
        for(int i=1;i<=maxn;++i)
        {
            int s=0;
            for(int j=i,k=1;j<=maxn;j+=i,++k)
            {
                s+=cnt[k];
                suf[j]+=cnt[i]*cnt[k];
            }
            ans+=cnt[i]*(n-s);
        }
        cin>>m;
        for(int i=maxn;i>=1;--i) suf[i]+=suf[i+1];
        //    cout<<suf[1]<<"!!"<<endl;
        for(int i=0;i<m;++i)
        {
            int x;cin>>x;
            cout<<suf[x]+ans<<'\n';
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