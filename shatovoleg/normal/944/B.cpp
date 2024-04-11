#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back

typedef long long ll;
typedef long double ld;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	int mx = -1000000000, mn = 1000000000;
	for (auto &x : arr)
	{
		cin >> x;
		mx = max(x, mx);
		mn = min(x, mn);
	}
	if (mx - mn < 2)
	{
		cout << n << endl;
		for (auto &x : arr)
			cout << x << " ";
		cout << endl;
		return 0;
	}
	vector<int> cnt(3, 0);
	for (auto &x : arr)
		++cnt[x - mn];
	int m = min(cnt[0], cnt[2]);
	if (2 * m > cnt[1])
	{
		cnt[1] += 2 * m;
		cnt[0] -= m;
		cnt[2] -= m;
	}
	else
	{
		m = cnt[1] / 2;
		cnt[0] += m;
		cnt[2] += m;
		cnt[1] %= 2;
	}
	cout << n - 2 * m << endl;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < cnt[i]; ++j)
			cout << i + mn << " ";
	cout << endl;
}