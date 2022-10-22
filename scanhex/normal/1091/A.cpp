#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int x = min(a, b - 1);
	x = min(x, c - 2);
	cout << x * 3 + 3 << '\n';
	return 0;
}