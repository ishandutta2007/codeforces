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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n;
    char s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        cin>>s;
        int sum=n;
        for(int i=1;i<n;++i)
        {
            if(s[i]=='U'&&s[i-1]=='R') --sum,s[i]=s[i-1]='W';
            if(s[i]=='R'&&s[i-1]=='U') --sum,s[i]=s[i-1]='W';
        }
        cout<<sum<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
aab

*/