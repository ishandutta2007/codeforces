#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4e5 + 10;

int f[N];

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_--) {
		int n;
		char c;
		cin >> n >> c;
		for (int i = 0; i < 2 * n; i++) f[i] = 0;
		string str;
		cin >> str;
		if (c == 'g') {
			cout << "0\n";
			continue;
		}
		str += str;
		for (int i = 2 * n - 1; ~i; i--) {
			if (str[i] == 'g') f[i] = i;
			else f[i] = f[i + 1];
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (c == str[i]) ans = max(ans, f[i] - i);
		}
		cout << ans << "\n";
	}
	return 0;	
}