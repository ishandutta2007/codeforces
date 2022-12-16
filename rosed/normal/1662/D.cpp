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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m,num1,num2;
    char a[N],b[N];
    bool dp[N];
    char s1[N],s2[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>(a+1)>>(b+1);
            n=strlen(a+1);
            m=strlen(b+1);
            num1=num2=0;
            int sum1=0,sum2=0;
            for(int i=1;i<=n;++i)
            {
                if(a[i]=='B') {sum1^=1;continue;}
                s1[++num1]=a[i];
                while(num1>1&&s1[num1]==s1[num1-1]) num1-=2;
            }
            for(int i=1;i<=m;++i)
            {
                if(b[i]=='B') {sum2^=1;continue;}
                s2[++num2]=b[i];
                while(num2>1&&s2[num2]==s2[num2-1]) num2-=2;
            }
            bool flag=1;
            if(num1!=num2||sum1!=sum2) flag=0;
            for(int i=1;i<=min(num1,num2);++i) if(s1[i]!=s2[i]) flag=0;
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


*/