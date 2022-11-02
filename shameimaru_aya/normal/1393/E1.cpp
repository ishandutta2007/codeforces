#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n , sum[110000] , srk[110000] , rk[2100000] , noww , ans , l , r;
int lcp[2100000] , lcp1[2100000] , lcp2[2100000] , nex[2100000];
long long dp[2100000] , ss[2100000] , val[2100000];
const int mod = 1e9 + 7;
string s[110000];
bool check( int pl1 , int pl2 )
{
	int u = lcp[sum[noww - 1]];
	if(u < min(pl1 , pl2)) return s[noww][u] <= s[noww + 1][u];
	if(pl1 < pl2)
	{
		u = pl1 + lcp2[sum[noww - 1] + pl1 + 1] + 1;
		if(u <= pl2) return s[noww][u] <= s[noww + 1][u - 1];
	}
	else
	{
		u = pl2 + lcp1[sum[noww - 1] + pl2];
		if(u < pl1) return s[noww][u] <= s[noww + 1][u + 1];
	}
	u = max(pl1 , pl2) + 1 + lcp[sum[noww - 1] + max(pl1 , pl2) + 1];
	if(u <= min(s[noww + 1].size() , s[noww].size()) - 1) return s[noww][u] <= s[noww + 1][u];
	return (s[noww].size() <= s[noww + 1].size() 
			|| (s[noww].size() - 1 == s[noww + 1].size() && pl2 == s[noww + 1].size() - 1));
}
void binary( int l , int r , int pl )
{
	if(l > r) return ;
	int mid = l + r >> 1;
//	cerr << l << ' ' << r << ' ' << mid << ' ' << rk[mid] << ' ' << pl << ' ';
	if(check(rk[mid] , pl))
	{
//		cerr << 1 << endl;
		ans = mid;
		binary(mid + 1 , r , pl);
	}
	else
	{
//		cerr << 0 << endl;
		binary(l , mid - 1 , pl);
	}
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) 
	{
		cin >> s[i] , s[i] += '$';
		sum[i] = sum[i - 1] + s[i].size();
	}
	for(int i = 1 ; i < n ; i++ )
	{
		for(int j = min(s[i].size() - 1 , s[i + 1].size() - 1) ; j >= 0 ; j-- )
			lcp[sum[i - 1] + j] = (s[i][j] == s[i + 1][j] ? lcp[sum[i - 1] + j + 1] + 1 : 0);
		for(int j = min(s[i].size() - 1 , s[i + 1].size() - 2) ; j >= 0 ; j-- )
			lcp1[sum[i - 1] + j] = (s[i][j] == s[i + 1][j + 1] ? lcp1[sum[i - 1] + j + 1] + 1 : 0);
		for(int j = min(s[i].size() - 1 , s[i + 1].size()) ; j >= 1 ; j-- )
			lcp2[sum[i - 1] + j] = (s[i][j] == s[i + 1][j - 1] ? lcp2[sum[i - 1] + j + 1] + 1 : 0);
//		for(int j = 1 ; j < min(s[i].size() , s[i + 1].size() + 1) ; j++ )
//			cerr << lcp2[sum[i - 1] + j] << ' ';
//		cerr << endl;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = s[i].size() - 2 ; j >= 0 ; j-- )
			nex[sum[i - 1] + j] = (s[i][j] == s[i][j + 1] ? nex[sum[i - 1] + j + 1] : j + 1);
		nex[sum[i] - 1] = s[i].size();
//		for(int j = 0 ; j <= s[i].size() - 2 ; j++ ) cerr << nex[sum[i - 1] + j] << ' '; cerr << endl;
	}
	
	for(int i = 1 ; i <= n ; i++ )
	{
		srk[i] = srk[i - 1];
		for(int j = 0 ; j < s[i].size() ; j = nex[sum[i - 1] + j] ) srk[i]++;
		l = srk[i - 1] + 1 , r = srk[i];
		for(int j = 0 ; j < s[i].size() ; j = nex[sum[i - 1] + j] )
		{
			if(s[i][j] < s[i][nex[sum[i - 1] + j]]) 
			{
				rk[r] = nex[sum[i - 1] + j] - 1; 
				val[r] = nex[sum[i - 1] + j] - j; r--;
			}
			else
			{
				rk[l] = nex[sum[i - 1] + j] - 1; 
				val[l] = nex[sum[i - 1] + j] - j; l++;
			} 
		}
	}
	
//	for(int i = 1 ; i <= n ; i++ ) 
//	{
//		for(int j = srk[i - 1] + 1 ; j <= srk[i] ; j++ ) cerr << rk[j] << ' ';
//		cerr << endl;
//	}
//	cerr << endl;
//	for(int i = 1 ; i <= n ; i++ ) 
//	{
//		for(int j = srk[i - 1] + 1 ; j <= srk[i] ; j++ ) cerr << val[j] << ' ';
//		cerr << endl;
//	}
//	cerr << endl;
	
	for(int i = 1 ; i <= srk[1] ; i++ ) ss[i] = ss[i - 1] + val[i];
	for(int i = 2 ; i <= n ; i++ )
	{
		noww = i - 1;
		for(int j = srk[i - 1] + 1 ; j <= srk[i] ; j++ )
		{
			ans = -1;
			binary(srk[i - 2] + 1 , srk[i - 1] , rk[j]);
//			cerr << ans - srk[i - 2] << ' ';
			if(~ans) dp[j] = val[j] * ss[ans] % mod;
		}
//		cerr << endl;
		ss[srk[i - 1] + 1] = dp[srk[i - 1] + 1]; 
		for(int j = srk[i - 1] + 2 ; j <= srk[i] ; j++ ) ss[j] = (dp[j] + ss[j - 1]) % mod;
//		for(int j = srk[i - 1] + 1 ; j <= srk[i] ; j++ ) cerr << dp[j] << ' '; cerr << endl;
	}
	printf("%lld" , ss[srk[n]]);
	return 0;
}
/*
2
abbba
abba 
*/