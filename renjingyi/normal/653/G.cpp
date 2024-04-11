#include <bits/stdc++.h>
using namespace std;
const int limit = 3e5;
const int maxn = limit + 5;
const long long mod = 1e9 + 7;
long long power(const long long &a, const long long &k)
{
	long long ans = 1, x = a % mod;
	for(long long i = k; i; i >>= 1, (x *= x) %= mod)
		if(i & 1)
			(ans *= x) %= mod;
	return ans;
}
vector<int> prime;
bool mark[maxn];
int to[maxn];
map<int, int> cnt[maxn];
long long fac[maxn], invfac[maxn];
long long calc(const int &n, const int &k)
{
	if(n < k || k < 0)
		return 0;
	return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}
long long q[maxn], qq[maxn];
int n;
void pre()
{
	for(int i = 2; i <= limit; i ++)
	{
		if(!mark[i])
		{
			prime.push_back(i);
			to[i] = i;
		}
		for(int j = 0; j < prime.size() && i * prime[j] <= limit; j ++)
		{
			mark[i * prime[j]] = 1;
			to[i * prime[j]] = prime[j];
			if(i % prime[j] == 0)
				break;
		}
	}
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	invfac[n] = power(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i --)
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	q[0] = 1;
	for(int i = 1; i <= n - 1; i ++)
		q[i] = (q[i - 1] + calc(n - 1, i)) % mod;
	for(int i = 1; i <= n; i ++)
		qq[i] = (qq[i - 1] + q[i - 1] + mod - q[n - i]) % mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	pre();
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		while(x > 1)
		{
			int now = to[x], t = 0;
			while(x % now == 0)
			{
				x /= now;
				t ++;
			}
			cnt[now][t] ++;
		}
	}
	long long ans = 0;
	for(int i = 1; i <= limit; i ++)
	{
		int t = n;
		for(map<int, int>::reverse_iterator it = cnt[i].rbegin(); it != cnt[i].rend(); it ++)
		{
			(ans += (qq[t] + mod - qq[t - it->second]) * it->first) %= mod;
			t -= it->second;
		}
	}
	cout << ans << endl;
	
	return 0;
}