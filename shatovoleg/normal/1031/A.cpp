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

vector<int> p;
vector<vector<int>> pos;

int mex(vector<int> v)
{
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (int i = 0; i < len(v); ++i)
		if (i != v[i])
			return i;
	return len(v);
}

int get_p(int w, int h)
{
	return 2 * (w - 1 + h - 1);
}

void run()
{
	int n, m, k;
	cin >> n >> m >> k;
	int res = 0;
	for (int i = 0; i < k; ++i)
		res += get_p(n - 4 * i, m - 4 * i);
	cout << res << endl;
}