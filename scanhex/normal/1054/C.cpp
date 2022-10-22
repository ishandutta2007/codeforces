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
	vector<int> l(n);
	for (auto& x : l)
		cin >> x;
	vector<int> r(n);
	for (auto& x : r)
		cin >> x;
	auto l1 = l, r1 = r;
	int cur = 0;
	int oo = 1e9;
	vector<int> ans(n, -oo);
	while (count(ans.begin(), ans.end(), -oo))
	{
		int mx = -oo;
		vector<int> inds;
		for (int j = 0; j < n; ++j)
		{
			if (ans[j] != -oo)
				continue;
			if (l[j] + r[j] > mx)
				inds.clear(), mx = l[j] + r[j];
			if (l[j] + r[j] == mx)
				inds.push_back(j);
		}
		for (int x : inds)
		{
			ans[x] = cur;
		}
		cur++;
		int ptr = 0;
		for (int j = 0; j < n; ++j)
		{
			 while (ptr < inds.size() && ans[ptr] < j)
				 ++ptr;
			 l[j] -= ptr;
			 r[j] -= (int)inds.size() - ptr;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int l = 0, r = 0;
		for (int j = 0; j < i; ++j)
			if (ans[j] > ans[i])
				++l;
		for (int j = i + 1; j < n; ++j)
			if (ans[j] > ans[i])
				++r;
		if (l != l1[i] || r != r1[i])
		{
			 cout << "NO\n";
			 return 0;
		}
	}
	cout << "YES\n";
	for (auto& x : ans)
		cout << x + 1 << ' ';
	cout << '\n';
	return 0;
}