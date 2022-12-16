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
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        if((__int128)(1+m)*m/2>(__int128)n)
        {
            cout<<"-1\n";
            return;
        }
        vector<int> tmp;
        for(int x=1;x*x<=n;++x)
        {
            if(n%x==0)
            {
                tmp.emplace_back(x);
                if(x*x!=n) tmp.emplace_back(n/x);
            }
        }
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        for(int x:tmp)
        {
            if((__int128)x*(1+m)*m/2>(__int128)n) continue;
            n-=x*(1+m)*m/2;
            if(n%x==0)
            {
                for(int i=1;i<m;++i) cout<<x*i<<' ';
                cout<<x*m+n<<'\n';
                return;
            }
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