#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, ans = 0;
	cin >> n;
	int ss = n;
	string s;
	cin >> s;
	vector<int> f(n * 2 + 1, n + 1);
	f[n] = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			ss++;
		else
			ss--;
		ans = max(ans, i + 1 - f[ss]);
		if (f[ss] > n)
			f[ss] = i + 1;
	}
	cout << ans << '\n';
}