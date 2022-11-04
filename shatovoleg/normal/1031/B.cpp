#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back
#define int ll

void usefiles(const string &s)
{
#ifndef LOCAL
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

void run();

signed main()
{
	// usefiles("post");
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

int mex(vector<int> v)
{
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (int i = 0; i < len(v); ++i)
		if (i != v[i])
			return i;
	return len(v);
}

void run()
{
	int n;
	cin >> n;
	vector<int> a(n - 1), b(n - 1);
	for (auto &x : a)
		cin >> x;
	for (auto &x : b)
		cin >> x;
	vector<vector<int>> dp(n, vector<int>(4, 0));
	for (int i = 0; i < 4; ++i)
		dp[0][i] = 1;
	vector<vector<int>> prv(n, vector<int>(4, -1));
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				if ((j | k) == a[i - 1] && (j & k) == b[i - 1] && cmax(dp[i][j], dp[i - 1][k]))
					prv[i][j] = k;
	}
	for (int i = 0; i < 4; ++i)
		if (dp.back()[i])
		{
			cout << "YES" << endl;
			int cur = i;
			vector<int> res;
			for (int j = n - 1; j > -1; --j)
			{
				res.pb(cur);
				cur = prv[j][cur];
			}
			// res.pb(cur);
			reverse(all(res));
			for (auto &x : res)
				cout << x << " ";
			cout << endl;
			return;
		}
	cout << "NO" << endl;
}