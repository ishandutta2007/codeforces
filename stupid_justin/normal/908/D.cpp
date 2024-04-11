#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7;
const int N=1005;
int invab,invb;
int k,pa,pb;
int dp[N][N];

int pow(int x,int y)
{
    int ans=1;
    while (y)
	{
		if (y&1) ans*=x,ans%=mod;
		x=x*x%mod;
		y>>=1;
	}
    return ans;
}
int dfs(int x,int y)
{
    if(x+y>=k) return ((x+y)+pa*invb)%mod; 
    if(dp[x][y]) return dp[x][y];
    else return dp[x][y]=(dfs(x+1,y)*pa+dfs(x,y+x)*pb)%mod*invab%mod;
}

signed main()
{
    cin>>k>>pa>>pb;
    invab=pow(pa+pb,mod-2);
    invb=pow(pb,mod-2);
    cout<<dfs(1,0)<<endl;
}