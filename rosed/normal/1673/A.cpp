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
    const int N=1e6+10,mod=1e4+7,inf=2e9;
    int n,m,sum;
    char s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>s;
            n=strlen(s);sum=0;
            for(int i=0;i<n;++i) sum+=s[i]-'a'+1;
            if(n==1)
            {
                cout<<"Bob ";
                cout<<s[0]-'a'+1<<'\n';
                continue;
            }
            cout<<"Alice ";
            if(n%2==0)
            {
                cout<<sum<<'\n';
            }
            else
            {
                sum-=2*min(s[0]-'a'+1,s[n-1]-'a'+1);
                cout<<sum<<'\n';
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

*/