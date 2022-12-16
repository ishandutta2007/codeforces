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
        int x,k;
        cin>>k>>x;
        int s1=(1+k)*k/2;
        if(x<=s1)
        {
            int l=1,r=k;
            while(l<=r)
            {
                int s=(1+mid)*mid/2;
                if(s>=x) r=mid-1;
                else l=mid+1;
            }
            cout<<r+1<<'\n';
            return;
        }
        x-=s1;
        int l=1,r=k-1;
        while(l<=r)
        {
            int s=(k-1+k-mid)*mid/2;
            if(s>=x) r=mid-1;
            else l=mid+1;
        }
        cout<<min(r+1+k,2*k-1)<<'\n';
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