#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	if (count(a.begin(), a.end(), a[0]) == n)
	{
		if (a[0] == 0)
		{
			cout << "YES\n";
			for (int i = 0; i < n; ++i)
				cout << 1 << ' ';
			cout << '\n';
			return 0;
		}
		cout << "NO\n";
		return 0;
	}
	int mem = *max_element(a.begin(), a.end());
	vector<nagai> ans(n, -1);
	int start = -1;
	for (int i = 0; i < n; ++i)
	{
		int j = i == 0 ? n - 1 : i - 1;
		if (a[j] < mem && a[i] == mem)
		{
			start = i;
			break;
		}
	}
	assert(start != -1);
	ans[start] = mem;
	int st1 = start == 0 ? n - 1 : start - 1;
	ans[st1] = mem * 2 + a[st1];
	for (int i = 1; i < n - 1; ++i)
	{
		int ind = (start - i - 1 + n) % n;
		int ind1 = ind + 1 == n ? 0 : ind + 1;
		ans[ind] = ans[ind1] + a[ind];
	}
	for (int i = 0; i < n; ++i)
	{
		int i1 = i + 1 == n ? 0 : i + 1;
		if (ans[i] % ans[i1] != a[i])
		{
			 cerr << "bad:(\n";
			 cout << "NO\n";
			 return 0;
		}
	}
	cout << "YES\n";
	for (nagai x : ans)
		cout << x << ' ';
	cout << '\n';
	return 0;
}