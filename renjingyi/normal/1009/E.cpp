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
const int maxn = 1e6 + 5;
int a[maxn], q[maxn];
long long dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		q[i] = (q[i - 1] + a[i]) % mod;
	}
	long long sum = 0;
	long long add = 0;
	long long add1 = 0, add2 = 0;
	for(int i = 1; i <= n; i ++)
	{	
		dp[i] = (add1 + add2 + q[i]) % mod;
		(add1 += dp[i]) %= mod;
		add2 <<= 1;
		(add2 += q[i]) %= mod;
	}
	cout <<	dp[n] << endl;
	
	return 0;
}