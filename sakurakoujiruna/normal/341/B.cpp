#include <iostream>
using namespace std;

const int N = 100011;

int a[N];

struct BIT
{
	int b[N];
	BIT() { }
	int lowbit(int x) { return x & (-x); }
	void change(int c, int pos)
	{
		pos += 2;
		for(int i = pos; i < N; i += lowbit(i))
			b[i] = max(b[i], c);
	}
	int query(int pos)
	{
		pos += 2;
		int ret = 0;
		for(int i = pos; i > 0; i -= lowbit(i))
			ret = max(ret, b[i]);
		return ret;
	}
}bit;

int dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int ans = 0;
	for(int i = 0; i < n; i ++)
	{
		dp[i] = bit.query(a[i]) + 1;
		bit.change(dp[i], a[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
	return 0;
}