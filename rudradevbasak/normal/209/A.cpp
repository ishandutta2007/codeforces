#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define s(n)	scanf("%d", &n);
#define sf(n)	scanf("%lf", &n);
#define ss(n)	scanf("%s", n);
#define all(v)	v.begin(),v.end()
#define FF		first
#define SS		second
#define tri(a,b,c)	mp(a,mp(b,c))
#define XX		first
#define YY		second.first
#define ZZ		second.second
#define fill(a,v)	memset(a,v,sizeof a)

#define debug(args...)	{dbg,args; cerr<<endl;}

struct debugger
{
	template <typename T>
	debugger & operator , (const T& v)
	{
		cerr << v << " ";
		return *this;
	}
} dbg;

void debugarr(int * a, int n)
{
	printf("[ ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("]\n");
}
	


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL>	VL;
typedef vector<vector<int> > VVI;
typedef pair<int, pair<int,int> > TRI;


int testnum;

int n;
int dp[1000005];
int sum[1000005];

void solve()
{
	fill(dp,0);
	fill(sum,0);
	
	LL ans = 0;
	LL mod = 1000000007;
	for(int i=1;i<=n;i++)
	{
		if(i<=1)
		{
			dp[i]=1;
			sum[i]=1;
		}
		else
		{
			dp[i] = (1+sum[i-1]) % mod;
			sum[i] = dp[i];
			sum[i] += sum[i-2];
			sum[i] %= mod;
		}
		ans += dp[i];
		ans %= mod;
	}
	cout<<ans<<endl;
	
}

void input()
{
	s(n);
}

int main()
{
	int T=1;
	for(int testnum=1;testnum<=T;testnum++)
	{
		input();
		solve();
	}
}