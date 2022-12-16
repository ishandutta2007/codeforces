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
        int n,m,k;
        cin>>k>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<m;++i) cin>>b[i];
        vector<int> c(n+m);
        int t1=0,t2=0;
        for(int i=0;i<n+m;++i)
        {
            if(t1<n&&(!a[t1]||a[t1]<=k))
            {
                if(!a[t1]) ++k;
                c[i]=a[t1++];
            }
            else
            {
                if(t2>=m||(b[t2]!=0&&k<b[t2]))
                {
                    cout<<"-1\n";
                    return;
                }
                if(!b[t2]) ++k;
                else if(k<b[t2])
                {
                    cout<<"-1\n";
                    return;
                }
                c[i]=b[t2++];
            }
        }
        for(int i=0;i<n+m;++i) cout<<c[i]<<" \n"[i==n+m-1];
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