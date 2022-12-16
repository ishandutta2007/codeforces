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
    int n,m,ans;
    char s[N];
    int tx,ty,s1,s2;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            cin>>(s+1);
            m=strlen(s+1);tx=ty=1;
            for(int i=1;i<=m;++i)
            {
                if(s[i]=='R') ++ty;
                if(s[i]=='D') ++tx;
            }
            //cout<<tx<<' '<<ty<<"!!!"<<endl;
            s1=tx,s2=ty;
            for(int i=1;i<=m;++i)
            {
                if(s[i]!=s[i-1]&&i!=1) break;
                if(s[i]=='R') --s2;
                else --s1;
            }
            if(tx==1||ty==1)
            {
                cout<<n<<'\n';
                continue;
            }
            //cout<<s1<<' '<<s2<<"!!"<<endl;
            ans=m+1+(n-tx)*s2+(n-ty)*s1+(n-tx)*(n-ty);
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
3
4
RD
5
DRDRDR
3
D

1
5
DDRRD

*/