#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
#define FOE(i,s,e) for(int i = (s); i <= (e); i++)
#define FOD(i,s,e) for(int i = (s); i >= (e); i--)
#define ll long long
#define pb push_back
#define mp make_pair

int n, m, x, y, z, k, w;
ll ans[2000005], output, mod = 1000000007ll, fac[2000005], tmp;
int is_prime[2000005], prime_list[2000005], p, least[2000005], inv[2000005];

vector<int> v[2000005];

ll f(int x, int y)
{
	if (y == 0) return 1;
	else
	{
		ll tmp = f(x, y / 2);
		tmp = tmp * tmp % mod;
		if (y % 2 == 1) tmp = tmp * x % mod;
		return tmp;
	}
}

int main ()
{
	scanf("%d %d", &n, &k);
	FOE(i, 1, 2000000) fac[i] = f(i, n);
	
	FOR(i, 2, 2100)
	{
		if (is_prime[i] == 1) continue;
		for (int j = i * i; j <= 2000000; j += i) 
			is_prime[j] = 1, least[j] = i;
	}
	
	FOE(i, 2, 2000000) if (is_prime[i] == 0) prime_list[p++] = i;
	FOE(i, 2, 2000000) if (is_prime[i] == 0) inv[i] = 1; else inv[i] = inv[i / least[i]] * -1;
	
	
	FOR(i, 0, p) 
	{
		if (prime_list[i] >= 3000) continue;
		for (int j = prime_list[i] * prime_list[i]; j <= 2000000; j += prime_list[i] * prime_list[i])
			inv[j] = 0;
	}

	FOE(i, 2, 2000000) if (inv[i] != 0) for (int j = i; j <= k; j += i) v[j].pb(i);
	
	FOE(i, 2, k)
	{
		ans[i] = ans[i - 1];
		
		FOR(j, 0, v[i].size())
		{
			x = v[i][j];
			y = i / x;
			ans[i] = (ans[i] + (fac[y] - fac[y - 1] + mod) % mod * inv[x]) % mod; // cnt[j] ^ n
		}
	//	printf("ans[%d] = %lld\n", i, ans[i]);
	}

	FOE(i, 1, k) 
	{
		tmp = (fac[i] + mod - ans[i]) % mod;
		tmp = (tmp ^ i) % mod;
		output += tmp;
		output %= mod;
	}
	printf("%lld\n", output);
	return 0;
}