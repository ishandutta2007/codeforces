#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int tim,x,y;
        cin>>tim>>x>>y;
        if(tim<x+y)
        {
            cout<<"NO\n";
            return;
        }
        if(!x&&!y)
        {
            cout<<"YES\n";
            return;
        }
        tim-=x+y;
        vector dp(120,vector<int>(120,0));
        dp[0][0]=tim;
        for(int i=0;i<120;++i)
        {
            for(int j=0;j<120;++j)
            {
                if(i>0) dp[i][j]+=dp[i-1][j]/2;
                if(j>0) dp[i][j]+=(dp[i][j-1]+1)/2;
            }
        }
        int nowx=0,nowy=0;
        while(nowx<120&&nowy<120)
        {
            if(nowx==x&&nowy==y)
            {
                cout<<"YES\n";return;
            }
            if(dp[nowx][nowy]&1) ++nowx;
            else ++nowy;
        }
        cout<<"NO\n";return;
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