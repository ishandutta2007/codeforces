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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int l=3,r=1e7;
        while(l<=r)
        {
            cout<<"?"<<' '<<1<<' '<<mid<<endl;
            int x;cin>>x;
            if(x==-1) r=mid-1;
            else
            {
                cout<<"?"<<' '<<mid<<' '<<1<<endl;
                int y;cin>>y;
                if(x==y)
                {
                    l=mid+1;
                }
                else
                {
                    cout<<"!"<<' '<<x+y<<endl;
                    return;
                }
                
            }
        }
        cout<<"!"<<' '<<l-1<<endl;
    }
}
signed main()
{
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/