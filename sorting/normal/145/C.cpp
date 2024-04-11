#include<bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;
const long long cntLucky = 1100;
const long long mod = 1e9 + 7;

unordered_map<long long, long long> Map;
long long cnt = 1;

bool isLucky(long long x)
{
	while(x > 9)
	{
		if(x % 10 != 4 && x % 10 != 7)
			return 0;
		x/=10;
	}

	if(x != 4 && x != 7)
		return 0;

	return 1;
}

long long lucky[cntLucky], a[N];
bool isLuckyArr[N];

long long dp[cntLucky][cntLucky];
bool b[cntLucky][cntLucky];

long long cnt2 = 0;

long long solve(long long pos, long long left)
{
	//cout << pos << " " << left << " hello\n";

	if(left < 0)
		return 0;

	if(pos == 0)
		return left == 0;

	if(b[pos][left])
		return dp[pos][left];

	b[pos][left] = 1;

	dp[pos][left] = ( solve(pos-1, left - 1) * lucky[pos] + solve(pos-1, left) ) % mod;

	return dp[pos][left];
}

long long fastPow(long long base, long long exp)
{
	if(base == 0)
		return 0;

	if(exp == 0)
		return 1;

	long long res = 1;

	if(exp % 2 == 1)
		res = base;

	long long tmp = fastPow(base, exp/2);

	res *= tmp;
	res %= mod;

	res *= tmp;
	res %= mod;

	return res;
}

long long fact[N];
bool calcFact[N];

long long factorial(long long n)
{
	if(n == 0)
		return 1;

	if(calcFact[n])
		return fact[n];

	calcFact[n] = true;

	fact[n] = factorial(n-1)*n;
	fact[n] %= mod;

	return fact[n];
}

long long combination(long long n, long long k)
{
	long long res = factorial(n);

	res *= fastPow(factorial(k), mod-2);
	res %= mod;

	res *= fastPow(factorial(n-k), mod-2);
	res %= mod;

	return res;
}

int main ()
{
	long long n, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for(long long i = 0; i < n; i++)
	{
		cin >> a[i];

		if(isLucky(a[i]))
		{
			isLuckyArr[i] = true;

			if(!Map[a[i]])
			{
				Map[a[i]] = cnt;
				cnt++;
			}

			lucky[ Map[ a[i] ] ] ++;
		}
		else
			cnt2++;
	}

	cnt--;
	
	long long res = 0;

	for(long long i = max(0ll, k-cnt); i <= min(cnt2, k); i++)
	{
		res += solve(cnt, k - i) * combination(cnt2, i);
		res %= mod;
	}

	cout << res << "\n";

	return 0;
}