#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            int s1=0,s2=0;
            for(int i=1;;++i)
            {
                if(s1+2*s2+1>n) break;
                ++s1;
                if(s1+2*s2+2>n) break;
                ++s2;
            }
            if(s1+2*s2<n) --s1,++s2;
            if(s1>s2)
            {
                cout<<'1';
                for(int i=1;i<=min(s1,s2);++i) cout<<"21";
                cout<<'\n';
            }
            else if(s2>s1)
            {
                cout<<'2';
                for(int i=1;i<=min(s1,s2);++i) cout<<"12";
                cout<<'\n';
            }
            else
            {
                for(int i=1;i<=s2;++i) cout<<"21";
                cout<<'\n';
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
5 5 7 2
5 0 7 2

1 3 1 2 5
1 2 3 1 4

*/