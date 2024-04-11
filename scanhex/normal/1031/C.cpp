#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	nagai x = 0;
	while (x * (x + 1) / 2 <= a + b)
		++x;
	--x;
	vector<int> ans1;
	vector<int> ans2;
	vector<bool> used(x + 1);
	for (int i = x; i > 0; --i)
		if (!used[i] && i <= a)
			ans1.push_back(i), used[i] = true, a -= i;
	for (int i = x; i > 0; --i)
		if (!used[i] && i <= b)
			ans2.push_back(i), used[i] = true, b -= i;
	cout << ans1.size() << '\n';
	for (int x : ans1)
		cout << x << ' ';
	cout << '\n';
	cout << ans2.size() << '\n';
	for (int x : ans2)
		cout << x << ' ';
	cout << '\n';
	return 0;
}