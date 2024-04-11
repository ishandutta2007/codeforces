#include <bits/stdc++.h> 
using namespace std;
int n , a , b , c , d , x , y , t1 , t2 , t3 , t4 , t5 , t6 , t7 , t8 , t9;
long long ans , fac[110000] , inv[110000];
const int mod = 998244353;
char str[110000];
long long C( int a , int b )
{
	return fac[a] * inv[b] % mod * inv[a - b] % mod;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for(int i = 2 ; i <= 100000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 100000 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 2 ; i <= 100000 ; i++ ) inv[i] = inv[i - 1] * inv[i] % mod;
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%s" , str);
		if(str[0] == 'B') a++;
		if(str[0] == 'W') c++;
		if(str[0] == '?') x++;
		if(str[1] == 'B') d++;
		if(str[1] == 'W') b++;
		if(str[1] == '?') y++;
		if(str[0] == '?' && str[1] == '?') t1++;
		if(str[0] == 'B' && str[1] == '?') t2++;
		if(str[0] == '?' && str[1] == 'W') t3++;
		if(str[0] == 'W' && str[1] == '?') t4++;
		if(str[0] == '?' && str[1] == 'B') t5++;
		if(str[0] == 'B' && str[1] == 'B') t6++;
		if(str[0] == 'B' && str[1] == 'W') t7++;
		if(str[0] == 'W' && str[1] == 'B') t8++;
		if(str[0] == 'W' && str[1] == 'W') t9++;
	}
	for(int i = b ; i <= n ; i++ )
	{
		int db = i - b , dd = y - db , da = i - a , dc = x - da;
		if(da < 0) continue;
		if(db < 0) continue;
		if(dc < 0) continue;
		if(dd < 0) continue;
		ans += C(x , da) * C(y , db) % mod;
		ans %= mod;
		if((!t9 || !t6) && n != 1)
		{
			da -= t3; db -= t2; dc -= t5; dd -= t4;
			if(da < 0 || db < 0 || dc < 0 || dd < 0) continue; 
			if(da != db) continue;
			(ans += mod - C(t1 , da)) %= mod;
			if(!(t2 + t3) && !(t5 + t4))
			{
				ans += ((da == t1) || (da == 0));
				continue;
			}
			if(!(t2 + t3)) ans += (da == 0);
			if(!(t5 + t4)) ans += (da == t1);
		}
	}
	cout << ans % mod;
    return 0;
} 
/*
3
??
??
??
*/