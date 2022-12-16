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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<string> s(n+1);
        int sum=0;
        bool flag=0;
        for(int i=0;i<n;++i)
        {
            cin>>s[i];
            for(int j=0;j<m;++j)
            {
                sum+=(s[i][j]=='1');
                if(j>0)
                {
                    flag|=(s[i][j]=='0'&&s[i][j-1]=='0');
                }
                if(i>0)
                {
                    flag|=(s[i][j]=='0'&&s[i-1][j]=='0');
                }
                if(i>0&&j>0)
                {
                    flag|=(s[i][j]=='0'&&s[i-1][j-1]=='0');
                }
                if(i>0&&j+1<m)
                {
                    flag|=(s[i][j]=='0'&&s[i-1][j+1]=='0');
                }
            }
        }
        if(sum==n*m) cout<<sum-2<<'\n';
        else if(flag) cout<<sum<<'\n';
        else cout<<sum-1<<'\n';
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