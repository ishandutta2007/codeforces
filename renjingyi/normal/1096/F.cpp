#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const long long mod = 998244353;
const int size = 450;
const int maxn = 2e5 + 5;
long long ksm(const long long &a, const long long &k)
{
	long long ans = 1;
	for(long long x = a % mod, asd = k; asd; asd >>= 1, (x *= x) %= mod)
		if(asd & 1)
			(ans *= x) %= mod;
	return ans;
}
int p[maxn];
bool mark[maxn];
long long inv[maxn];
namespace BIT
{
	int n;
	int s[maxn];
	#define lowbit(x) (x & -x)
	void add(const int &p)
	{
		for(int i = p; i <= n; i += lowbit(i))
			s[i] ++;
	}
	int calc(const int &p)
	{
		int ans = 0;
		for(int i = p; i; i -= lowbit(i))
			ans += s[i];
		return ans;
	}
}
vector<int> asd;
long long f[maxn];
long long fac[maxn], invfac[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		inv[i] = ksm(i, mod - 2);
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[n] = ksm(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i --)
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	BIT::n = n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[i];
		if(p[i] > 0)
			mark[p[i]] = 1;
	}
	for(int i = 1; i <= n; i ++)
		if(!mark[i])
			asd.push_back(i);
	long long ans = 0;
	for(int i = n; i >= 1; i --)
		if(p[i] > 0)
		{
			(ans += BIT::calc(p[i])) %= mod;
			BIT::add(p[i]);
		}
	if(asd.size() == 0)
	{
		cout << ans << endl;
		return 0;
	}
	for(int i = 1; i <= asd.size(); i ++)
		f[i] = (i * f[i - 1] + (long long)i * (i - 1) / 2 % mod * fac[i - 1]) % mod;
	(ans += f[asd.size()] * invfac[asd.size()]) %= mod;
	long long tmp = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(p[i] > 0)
			(tmp += lower_bound(asd.begin(), asd.end(), p[i]) - asd.begin()) %= mod;
		else
			(ans += tmp * inv[asd.size()]) %= mod;
	}
	tmp = 0;
	for(int i = n; i >= 1; i --)
	{
		if(p[i] > 0)
			(tmp += (int)asd.size() - (lower_bound(asd.begin(), asd.end(), p[i]) - asd.begin())) %= mod;
		else
			(ans += tmp * inv[asd.size()]) %= mod;
	}
	cout << ans << endl;
	
	return 0;
}