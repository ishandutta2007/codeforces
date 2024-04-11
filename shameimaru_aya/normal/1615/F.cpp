#include<bits/stdc++.h>
using namespace std;
int T , n , a[2200] , b[2200];
long long ans , pre[2200][4400] , suf[2200][4400];
const int mod = 1e9 + 7;
string s;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		cin >> s;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			if(s[i - 1] == '?') a[i] = 2;
			else a[i] = s[i - 1] - '0';
		}
		cin >> s;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			if(s[i - 1] == '?') b[i] = 2;
			else b[i] = s[i - 1] - '0';
		}
		for(int i = 1 ; i <= n ; i += 2 ) a[i] ^= 1 , b[i] ^= 1;
		for(int i = 0 ; i <= n + 1 ; i++ )
			for(int j = 0 ; j <= 2 * n ; j++ ) pre[i][j] = suf[i][j] = 0;
		pre[0][n] = suf[n + 1][n] = 1; 
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = n - i + 1 ; j <= n + i - 1 ; j++ )
			{
				if(a[i] != 1)
				{
					if(b[i] != 1) (pre[i][j] += pre[i - 1][j]) %= mod;
					if(b[i] != 0) (pre[i][j + 1] += pre[i - 1][j]) %= mod;
				}
				if(a[i] != 0)
				{
					if(b[i] != 1) (pre[i][j - 1] += pre[i - 1][j]) %= mod;
					if(b[i] != 0) (pre[i][j] += pre[i - 1][j]) %= mod;
				}
			}
		}
		for(int i = n ; i >= 1 ; i-- )
		{
			for(int j = n - (n - i) ; j <= n + (n - i) ; j++ )
			{
				if(a[i] != 1)
				{
					if(b[i] != 1) (suf[i][j] += suf[i + 1][j]) %= mod;
					if(b[i] != 0) (suf[i][j + 1] += suf[i + 1][j]) %= mod;
				}
				if(a[i] != 0)
				{
					if(b[i] != 1) (suf[i][j - 1] += suf[i + 1][j]) %= mod;
					if(b[i] != 0) (suf[i][j] += suf[i + 1][j]) %= mod;
				}
			}
		}
		ans = 0;
		for(int i = 1 ; i <= n ; i++ )
			for(int j = -n ; j <= n ; j++ )
				(ans += pre[i][j + n] * suf[i + 1][n - j] % mod * abs(j) % mod) %= mod;
		cout << ans << '\n';
	}
    return 0;
}
/*
*/