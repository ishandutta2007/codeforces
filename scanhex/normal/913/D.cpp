#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	int n;
	nagai T;
	cin >> n >> T;
	vector<nagai> a(n), t(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> t[i];
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y)
			{
				return a[x] > a[y];
			});
	set<pair<int, int>> ms;
	int pt = 0;
	nagai sum = 0;
	for (int i = n; i >= 0; --i)
	{
		while (pt < n && a[ord[pt]] >= i)
		{
			sum += t[ord[pt]];
			ms.insert({t[ord[pt]], ord[pt]});
			++pt;
		}
		while (ms.size() > i)
		{
			sum -= ms.rbegin()->first;
			auto it = ms.end();
			--it;
			ms.erase(it);
		}
		if (ms.size() == i && sum <= T)
		{
			cout << i << endl;
			cout << i << endl;
			for (auto x : ms)
				cout << x.second + 1 << ' ';
			cout << endl;
			return 0;
		}
	}
	return 0;
}