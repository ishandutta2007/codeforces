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
        if(n==1)
        {
            int x;cin>>x;
            cout<<"1 1"<<'\n';
            cout<<-x<<'\n';
            cout<<"1 1"<<'\n';
            cout<<0<<'\n';
            cout<<"1 1"<<'\n';
            cout<<0<<'\n';
            return;
        }
        vector<int> a(n+1);
        function<int(int&,int&,int,int)> exgcd=[&](int &x,int &y,int a,int b) -> int
        {
            if(!b){x=1,y=0;return a;}
            int g=exgcd(y,x,b,a%b);
            y-=a/b*x;
            return g;
        };
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        cout<<"1 1\n";
        cout<<-a[1]<<'\n';
        a[1]=0;
        cout<<2<<' '<<n<<'\n';
        for(int i=2;i<=n;++i)
        {
            int x,y;
            int g=exgcd(x,y,n,n-1);
            x*=-a[i],y*=-a[i];
            y=(y%n+n)%n;
            cout<<y*(n-1)<<' ';
            a[i]+=y*(n-1);
        }
        cout<<'\n';
        cout<<1<<' '<<n<<'\n';
        for(int i=1;i<=n;++i) cout<<-a[i]<<' ';
            cout<<'\n';
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