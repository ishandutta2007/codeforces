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
        vector<int> a(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        if(a[0]==a[1]&&a[1]==a[2])
        {
            int t=upper_bound(a.begin(),a.end(),a[0])-a.begin();
            cout<<t*(t-1)*(t-2)/6<<'\n';
        }
        else if(a[0]!=a[1]&&a[1]==a[2])
        {
            int t=upper_bound(a.begin(),a.end(),a[1])-a.begin();
            --t;
            cout<<t*(t-1)/2<<'\n';
        }
        else if(a[0]==a[1]&&a[1]!=a[2])
        {
            int t=upper_bound(a.begin(),a.end(),a[2])-a.begin();
            cout<<t-2<<'\n';
        }
        else if(a[0]!=a[1]&&a[1]!=a[2])
        {
            int t=upper_bound(a.begin(),a.end(),a[2])-a.begin();
            cout<<t-2<<'\n';
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