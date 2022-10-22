#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (auto& x : a)
		cin >> x;
	vector<bool> used(n);
	int cnt = 0;
	for (int i = 0; i < 2 * n; ++i)
	{
		if (used[a[i]])
			continue;
		int j = find(a.begin() + i + 1, a.end(), a[i]) - a.begin();
		used[a[i]] = true;
		for (int k = j - 1; k > i; --k)
			swap(a[k], a[k + 1]), ++cnt;
	}
	cout << cnt << '\n';

}