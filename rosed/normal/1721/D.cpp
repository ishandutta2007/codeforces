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
        int n;
        cin>>n;
        vector<int> a(n),c(n);
        vector<int> b(n),d(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        int ans=0;
        typedef array<int,2> pr;
        vector<pr> tmp[2];
        tmp[0].emplace_back(pr{0,n-1});
        int opt=0;
        for(int k=29;~k;--k)
        {
            bool flag=1;
            for(auto [l,r]:tmp[opt])
            {
                int s1=0,s2=0,s3=0,s4=0;
                for(int i=l;i<=r;++i)
                {
                    if((a[i]>>k)&1) ++s1;
                    else ++s2;
                    if((b[i]>>k)&1) ++s3;
                    else ++s4;
                }
                if(s1==s4&&s2==s3);
                else
                {
                    flag=0;break;
                }
            }
            if(!flag)
            {
                tmp[opt^1]=tmp[opt];
                opt^=1;
                continue;
            }
            ans|=(1<<k);
            tmp[opt^1].clear();
            for(auto [l,r]:tmp[opt])
            {
                int t1=l,t2=l;
                for(int i=l;i<=r;++i)
                {
                    if((a[i]>>k)&1) c[t1++]=a[i];
                    if((b[i]>>k)&1);
                    else d[t2++]=b[i];
                }
                int ka=t1;
                if(l<=t1-1) tmp[opt^1].emplace_back(pr{l,t1-1});
                for(int i=l;i<=r;++i)
                {
                    if((a[i]>>k)&1);
                    else c[t1++]=a[i];
                    if((b[i]>>k)&1) d[t2++]=b[i];
                }
                if(ka<=r)tmp[opt^1].emplace_back(pr{ka,r});
            }
            for(int i=0;i<n;++i) a[i]=c[i],b[i]=d[i];
            opt^=1;
        }
        cout<<ans<<'\n';
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