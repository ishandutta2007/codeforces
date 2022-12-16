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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(a>b)
        {
            if(a!=n/2+1||b!=n/2)
            {
                cout<<"-1\n";
                return;
            }
            for(int i=n;i>=1;--i) cout<<i<<" \n"[i==1];
            return;
        }
        int tl=n-b+1,tr=n-a;
        //cout<<tl<<' '<<tr<<"!!!"<<endl;
        if(tl<=n/2&&n/2<=tr)
        {
            vector<int> s(n+1);
            int t=1,x=n;
            while(x>b) s[t++]=x--;
            --x;
            while(t<n/2) s[t++]=x--;
            s[t++]=a;
            s[t++]=b;
            while(t<=n)
            {
                if(x==a) --x;
                s[t++]=x--;
            }
            for(int i=1;i<=n;++i) cout<<s[i]<<" \n"[i==n];
        }
        else
        {
            cout<<"-1\n";
            return;
        }
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