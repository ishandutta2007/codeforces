#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,x,y;
        cin>>n>>x>>y;
        if(x>y) swap(x,y);
        if(x>0&&y>0)
        {
            cout<<-1<<'\n';return;
        }
        if(x==0&&y==0)
        {
            cout<<-1<<'\n';return;
        }
        if((n-1)%y)
        {
            cout<<-1<<'\n';return;
        }
        int pos=1,sum=0;
        for(int i=2;i<=n;++i)
        {
            if(sum==y)
            {
                pos=i;
                sum=1;
            }
            else ++sum;
            cout<<pos<<' ';
        }
        cout<<'\n';
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