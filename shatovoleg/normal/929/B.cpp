#include <bits/stdc++.h>

using namespace std;

#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b)
{
	if (a > b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b)
{
	if (a < b)
	{
		a = b;
		return false;
	}
	return true;
}

int ccc(string &s, int i) // When you don't know how to call finction
{
	int res = 0;
	if (i > 0)
		res += s[i - 1] == 'S';
	if (i + 1 < len(s))
		res += s[i + 1] == 'S';
	return res;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> arr(n);
	for (auto &x : arr)
		cin >> x;
	for (int i = 0; i < 3; ++i)
	{
		if (k == 0)
			break;
		for (auto &x : arr)
			for (int j = 0; j < len(x); ++j)
			{
				if (k == 0)
					break;
				if (x[j] == '.' && ccc(x, j) == i)
				{
					x[j] = 'x';
					--k;
				}
			}
	}
	int ans = 0;
	for (auto &x : arr)
		for (int i = 0; i < len(x); ++i)
			if (x[i] == 'S')
			{
				if (i > 0 && x[i - 1] != '-' && x[i - 1] != '.')
					++ans;
				if (i + 1 < len(x) && x[i + 1] != '-' && x[i + 1] != '.')
					++ans;
			}
	cout << ans << endl;
	for (auto &x : arr)
		cout << x << endl;
}