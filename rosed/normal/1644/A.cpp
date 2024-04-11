#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=201314,inf=2e9;
    int n;
    char a[N];
    int s1,s2,s3,flag;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>a;s1=s2=s3=0;flag=1;
            for(int i=0;i<6;++i)
            {
                if(a[i]=='r') s1=1;
                if(a[i]=='b') s2=1;
                if(a[i]=='g') s3=1;
                if(a[i]=='R'&&!s1) flag=0;
                if(a[i]=='B'&&!s2) flag=0;
                if(a[i]=='G'&&!s3) flag=0;
            }
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