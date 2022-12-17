#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct BIT
{
	#define lowbit(x) (x & -x)
	int c[maxn << 1];
	void add(const int &p, const int &n)
	{
		for(int i = p; i <= n; i += lowbit(i))
			c[i] ++;
	}
	int query(const int &p)
	{
		if(p <= 0)
			return 0;
		int ans = 0;
		for(int i = p; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
}b1, b2;
long long n, m;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	int sum = 0, cnt = 0;
	b1.add(n, n + n);
	b2.add(n, n + n);
	long long ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		x = x == m ? 0 : (x < m ? -1 : 1);
		sum += x;
		cnt += x == 0;
		ans += b1.query(cnt - sum + n) + b2.query(cnt + sum - 1 + n);
		if(i < n)
		{
			b1.add(cnt - sum + n, n + n);
			b2.add(cnt + sum + n, n + n);
		}
	}
	cout << ans - n - n * (n - 1) / 2 << endl;
	
	return 0;
}