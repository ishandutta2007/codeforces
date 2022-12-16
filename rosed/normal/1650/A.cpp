#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=1e9+7;
    int n,m;
    int a[N];
    char s[N],ch;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>(s+1);cin>>ch;
            bool flag=0;
            n=strlen(s+1);
            for(int i=1;i<=n;i+=2) flag|=(s[i]==ch);
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
5 5
5 1 2
6 2 3
4 3 5
6 2 4
5 1 3

*/