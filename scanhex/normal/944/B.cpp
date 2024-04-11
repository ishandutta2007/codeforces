#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;
typedef long double db;
typedef complex<db> cp;


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto& x : arr)
		cin >> x;
	int mx = *max_element(arr.begin(), arr.end());
	int mn = *min_element(arr.begin(), arr.end());
	if (mx - mn <= 1)
	{
		cout << n << '\n';
		for (auto& x : arr)
			cout << x << ' ';
		cout << '\n';
		return 0;
	}
	int a = count(arr.begin(), arr.end(), mn);
	int b = count(arr.begin(), arr.end(), mn + 1);
	int c = count(arr.begin(), arr.end(), mn + 2);
	int ans1 = 2 * min(a, c);
	int ans2 = b / 2 * 2;
	if (ans1 > ans2)
	{
		cout << n - ans1 << '\n';
		for (int i = 0; i < a - min(a, c); ++i)
			cout << mn << ' ';
		for (int j = 0; j < b + min(a, c) * 2; ++j)
			cout << mn + 1 << ' ';
		for (int i = 0; i < c - min(a, c); ++i)
			cout << mn + 2 << ' ';
		cout << '\n';
	}
	else
	{
		cout << n - ans2 << '\n';
		for (int i = 0; i < a + b / 2; ++i)
			cout << mn << ' ';
		for (int j = 0; j < b % 2; ++j)
			cout << mn + 1 << ' ';
		for (int i = 0; i < c + b / 2; ++i)
			cout << mn + 2 << ' ';
		cout << '\n';
	}
}