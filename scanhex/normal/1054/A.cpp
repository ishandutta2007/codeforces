#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int tlift = t3 * 3 + t2 * abs(x - y) + t2 * abs(x - z);
	int tmem = t1 * abs(x - y);
	if (tlift <= tmem)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}