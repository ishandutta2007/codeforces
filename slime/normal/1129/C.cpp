#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define maxn 4005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
int a[maxn];
ll dp[maxn];
int s[maxn]; 
ll md = mod;
void cal(int len)
{
	dp[len + 1] = 1;
	for(int i = len; i >= 1; i--)
	{
		dp[i] = 0;
		int ns = 0;
		for(int j = i; j <= i + 3 && j <= len; j++)
		{
			ns = ns * 2 + s[j];
			if((j != i + 3) || (ns != 3 && ns != 5 && ns != 14 && ns != 15))
				dp[i] += dp[j + 1], 
				dp[i] %= mod;
		}
	}
	//cout<<"WK"<<len<<" "<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<endl;
	return ;
}
int ch[maxn * maxn][2];
int rt = 1;
int cnt = 2;
unordered_map<ll, int> hv;
int main()
{
	md *= (mod + 2);
	int t;
	cin>>t;
	for(int i = 1; i <= t; i++)
		cin>>a[i];
	ll ans = 0;
	for(int i = 1; i <= t; i++)
	{
		int ls = 0;
		int npl = rt;
		for(int j = i; j >= 1; j--)
		{
			if(!ch[npl][a[j]]) 
				ch[npl][a[j]] = cnt++, ls = max(ls, j);
			npl = ch[npl][a[j]];
		}
		for(int j = 1; j <= i; j++)
			s[j] = a[j];
	//	cout<<"CAN"<<i<<" "<<ls<<endl;
		cal(i);
		for(int j = 1; j <= ls; j++)
			ans += dp[j], 
			ans %= mod;
		cout<<ans<<endl;
	}
	return 0;
}