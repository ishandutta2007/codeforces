#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector<int> b(n);
	for (auto& x : b)
		cin >> x;
	vector<int> q = {0};
	vector<int> d(n, -1);
	d[0] = 0;
	for (int i = 0; i < q.size(); ++i)
	{
		int x = q[i];
		for (int j = 0; j < n; ++j)
		{
			if (j < x && b[x] && b[j] || j > x && a[x] && a[j])
			{
				if (d[j] == -1)
					d[j] = 0, q.push_back(j);
			}
		}
	}
	if (d[s - 1] == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}