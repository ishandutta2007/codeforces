#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	n = max(1000, n / 2);
	for (int i = 0; i < n; ++i)
		cout << 9;
	for (int i = 0; i < n; ++i)
		cout << 0;
	cout << 1;
	cout << '\n';
	for (int i = 0; i < n + 1; ++i)
		cout << 9;
	return 0;
}