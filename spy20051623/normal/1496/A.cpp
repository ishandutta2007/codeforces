#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k, i, j, cnt;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cin >> s;
		i = 0;
		j = n - 1;
		cnt = 0;
		while (s[i] == s[j] && i < j) {
			++cnt;
			++i;
			--j;
		}
		if (n == cnt * 2 && k == cnt)
			cout << "NO" << endl;
		else if (cnt >= k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}