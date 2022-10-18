#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, k;
	cin >> n >> k;
	int t = 0, days = 0, left = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		left += a;
		t += min(left, 8); // no more than 8
		left -= min(left, 8);
		days++;
		if (t >= k) break;
	}
	if (t < k) cout << -1;
	else cout << days;
	cout << endl;
	exit(0);
}