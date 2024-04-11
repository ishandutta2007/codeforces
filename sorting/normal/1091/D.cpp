#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const long long N = 1e6 + 7;

long long fact[N];

long long fast_pow(long long base, long long exp)
{
	if(exp == 0)
		return 1;

	if(exp & 1)
	{
		long long res = base * fast_pow(base, exp-1ll);
		res %= mod;

		return res;
	}

	long long tmp = fast_pow(base, exp >> 1ll);

	return (tmp * tmp) % mod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	fact[0] = 1;

	for(int i = 1; i <= n; i++)
	{
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
	}

	long long res = 0;

	for(int i = 0; i < n; i++)
	{
		long long curr = fact[n-i] - 1;
		curr %= mod;

		while(curr < 0)
			curr += mod;

		//cout << curr << endl;

		curr *= fact[n];
		curr %= mod;

		curr *= fast_pow(fact[n-i], mod-2);
		curr %= mod;

		//cout << curr << endl;

		res += curr;
		res %= mod;
	}

	res++;
	res %= mod;

	cout << res << "\n";

	return 0;
}