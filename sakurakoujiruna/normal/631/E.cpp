#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200011;
typedef long long intl;

intl a[N];
intl sum[N];

intl dp[N];

#define x first
#define y second
pair <intl, intl> sta[N];

intl cross(pair <intl, intl> lhs, pair <intl, intl> rhs)
{
	return lhs.x * rhs.y - lhs.y * rhs.x;
}
pair <intl, intl> sub(pair <intl, intl> lhs, pair <intl, intl> rhs)
{
	return {lhs.x - rhs.x, lhs.y - rhs.y};
}

intl calc(intl k, int n)
{
	return -k * sta[n].x + sta[n].y;
}
intl solve(intl k, int n)
{
	int left = 0, right = n;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		if(calc(k, mid) >= calc(k, mid - 1))
			left = mid;
		else
			right = mid;
	}
	return calc(k, left);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	intl offset = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		offset += a[i] * i;
		sum[i] = sum[i - 1] + a[i];
	}
	if(n == 1)
	{
		cout << offset << '\n';
		return 0;
	}
	fill(dp + 1, dp + n + 1, -1e18);
	int top = 0;
	sta[top ++] = {n, -sum[n]};
	for(int i = n - 1; i >= 1; i --)
	{
		dp[i] = max(dp[i], solve(-a[i], top) + sum[i] - i * a[i]);
		while(top >= 2 && cross(sub({i, -sum[i]}, sta[top - 1]),
			sub(sta[top - 1], sta[top - 2])) >= 0)
			top --;
		sta[top ++] = {i, -sum[i]};
	}
	
	top = 0;
	sta[top ++] = {1, 0};
	for(int i = 2; i <= n; i ++)
	{
		dp[i] = max(dp[i], solve(-a[i], top) + sum[i - 1] - i * a[i]);
		while(top >= 2 && cross(sub({i, -sum[i - 1]}, sta[top - 1]),
			sub(sta[top - 1], sta[top - 2])) <= 0)
			top --;
		sta[top ++] = {i, -sum[i - 1]};
	}

	intl ans = offset;
	for(int i = 1; i <= n; i ++)
		ans = max(ans, dp[i] + offset);
	cout << ans << '\n';
	return 0;
}