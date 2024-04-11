#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 17;
struct it
{
	int t[2 * N];
	it()
	{
		fill(t, t + 2 * N, 0);
	}
	void set(int x, int val)
	{
		x += N;
		t[x] = val;
		while (x > 1)
			t[x >> 1] = max(t[x], t[x ^ 1]), x >>= 1;
	}
	int get(int l, int r)
	{
		l += N;
		r += N;
		int ans = 0;
		while (l < r)
		{
			if (l & 1)
				ans = max(ans, t[l++]);
			if (r & 1)
				ans = max(ans, t[--r]);
			l >>= 1, r >>= 1;
		}
		return ans;
	}
};

int mx(vector<int> a)
{
	int m = a.size();
	int inf = 1e9;
	vector<int> d(m + 1, inf);
	vector<int> dp(m);
	d[0] = -1;
	for (int i = 0; i < m; ++i)
	{
		int kek = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		--kek;
		dp[i] = kek + 1;
		d[kek + 1] = min(d[kek + 1], a[i]);
	}
	vector<int> d1(m + 1, inf);
	vector<int> dp1(m);
	d1[0] = -1;
	for (int i = m - 1; i >= 0; --i)
	{
		int kek = upper_bound(d1.begin(), d1.end(), a[i]) - d1.begin();
		--kek;
		dp1[i] = kek + 1;
		d1[kek + 1] = min(d1[kek + 1], a[i]);
//		cerr << dp1[i] << ' ';
	}
//	cerr << endl;
	it myit;
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		ans = max(ans, dp1[i] + myit.get(0, a[i] + 1));
		int mem = myit.get(a[i], a[i] + 1);
		myit.set(a[i], max(mem, dp[i]));
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (m == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n == 1)
	{
		int l, r;
		cin >> l >> r;
		if (l == r)
			cout << m - 1 << endl;
		else
			cout << m << endl;
		return 0;
	}
	vector<int> arr(m + 1);
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;
		--l;
		++arr[l];
		--arr[r];
	}
	int cur = 0;
	vector<int> a(m);
	for (int i = 0; i < m; ++i)
		cur += arr[i], a[i] = cur;
	cout << mx(a) << endl;
}