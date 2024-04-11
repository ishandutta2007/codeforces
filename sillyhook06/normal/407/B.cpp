#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

const int MOD = 1000000007;
int N, p[1004], f[1003];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)	p[i] = read();
	
	f[0] = 0;
	int ans = 0;
	for (int i = 1; i <= N; ++ i)
	{
		f[i] = 1;
		for (int j = p[i]; j < i; ++ j)
			f[i] = (f[i] + f[j] + 1) % MOD;
		ans = (ans + f[i] + 1) % MOD;
	}
	cout << ans << endl;
	

	return 0;
}