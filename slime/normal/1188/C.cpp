#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 1005
#define sq 355
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n, k;
int a[maxn];
int nx[maxn]; 
int ans = 0;
int dp[maxn][maxn];
int s[maxn][maxn];
int cal(int r)
{
	int pl = 1;
	for(int i = 1; i <= n; i++)
	{
		while(pl <= n && a[pl] - a[i] < r) pl++;
		nx[i] = pl;
	}
	for(int i = 0; i <= k - 1; i++)
	{
		for(int j = 1; j <= n; j++)
			if(i == 0) dp[i][j] = 1;
			else dp[i][j] = s[i - 1][nx[j]];
		for(int j = n; j >= 1; j--)
		{
			s[i][j] = s[i][j + 1] + dp[i][j];
			if(s[i][j] >= mod) s[i][j] -= mod;
		}
	}
	//cout<<r<<" "<<s[k - 1][1]<<endl;
	return s[k - 1][1];
}
int main()
{
	cin>>n>>k;
	int mx = 0;
	for(int i = 1; i <= n; i++)
		cin>>a[i], 
		mx = max(mx, a[i]);
	sort(a + 1, a + n + 1);
	for(int j = 1; j <= mx / (k - 1); j++)
		ans = (ans + cal(j)) % mod;
	cout<<ans<<endl;
	return 0;
} 
/*
2 1 1 5

 
*/