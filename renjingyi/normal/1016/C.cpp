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
const int maxn = 3e5 + 5;
long long a[maxn], b[maxn];
long long q1[maxn], q2[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	for(int i = n; i >= 1; i --)
	{
		q1[i] = q1[i + 1] + a[i];
		q2[i] = q2[i + 1] + b[i];
	}
	long long x1 = 0, x2 = 0;
	long long t = 0;
	for(int i = 1; i <= n; i ++)
	{
		x1 += t * a[i];
		x2 += t * b[i];
		t ++;
	}
	for(int i = n; i >= 1; i --)
	{
		x1 += t * b[i];
		x2 += t * a[i];
		t ++;
	}
	long long ans = 0, now = 0;
	x2 -= (2 * n - 1) * a[1];
	for(int i = 1; i <= n; i ++)
	{
		if(i & 1)
		{
			ans = max(ans, now + x1 + (q1[i] + q2[i]) * (i - 1));
			now += a[i] * 2 * (i - 1);
			x1 -= (i - 1) * a[i] + (2 * n - i) * b[i] + i * a[i + 1] + (2 * n - i - 1) * b[i + 1];
			now += b[i] * (2 * (i - 1) + 1);
		}
		else
		{
			ans = max(ans, now + x2 + (q1[i] + q2[i]) * (i - 1));
			now += b[i] * 2 * (i - 1);
			x2 -= (i - 1) * b[i] + (2 * n - i) * a[i] + i * b[i + 1] + (2 * n - i - 1) * a[i + 1];
			now += a[i] * (2 * (i - 1) + 1);
		}
	}
	ans = max(ans, now);
	cout << ans << endl;
	
	return 0;
}