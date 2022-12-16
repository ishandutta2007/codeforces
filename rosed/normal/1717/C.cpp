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
        vector<int> a(n),b(n),c(n);
        bool flag=0;
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
            flag|=(b[i]<a[i]);
            c[i]=a[i]==b[i];
        }
        for(int i=0;i<n;++i)
        {
            int t=(i+1)%n;
            if(b[i]-b[t]>1&&!c[i]) flag=1;
        }
        if(flag)
        {
            cout<<"NO\n";
            return;
        }
        else cout<<"YES\n";
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
1 7 5 6 8 2 6 5

0 8 5 6 8 0 8 5
3
5 6 5
3 8 5
2
3
8
*/