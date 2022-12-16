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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    map<int,int> dp[20];
    inline void main()
    {
        int n,m;
        cin>>n>>m;

        vector<int> s;
        vector<int> pw(20),ppre(20);
        function<int(int,int,int,int)> dfs=[&](int pos,int lim,int pre,int sum) -> int
        {
            if(pos==-1)
            {
                return sum>=m;
            }
            if(!lim&&pre&&sum>=m)
            {
                return pw[pos+1];
            }
            if(!lim&&pre&&m-sum>9*ppre[pos]) return 0;
            if(!lim&&pre&&dp[pos].find(sum)!=dp[pos].end()) return dp[pos][sum];
            int up=(lim?s[pos]:9);
            int ret=0;
            
            for(int i=0;i<=up;++i)
            {
                ret+=dfs(pos-1,lim&(i==up),pre|i,sum+i*(pw[pos]-1));
            }
            if(!lim&&pre) dp[pos][sum]=ret;
            return ret;
        };
        auto solve=[&](int x) -> int
        {
            while(x) s.emplace_back(x%10),x/=10;
            //reverse(s.begin(),s.end());
            int num=s.size();
            pw[0]=1;
            for(int i=1;i<=num;++i) pw[i]=pw[i-1]*10;
            ppre[0]=0;
            for(int i=1;i<=num;++i) ppre[i]=ppre[i-1]+(pw[i]-1);
            return dfs(num-1,1,0,0);
        };
        cout<<solve(n)<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/