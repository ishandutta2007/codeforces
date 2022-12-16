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
        int n;
        cin>>n;
        int sum=0;
        vector<int> a(n+1);
        for(int i=1;i<n;++i)
        {
            a[i]=i;
            sum^=i;
        }
        a[n]=sum;
        if(a[n]==a[n-1]) a[n-2]|=(1<<20);
        else a[n-1]|=(1<<20);
        a[n]|=(1<<20);
        for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
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