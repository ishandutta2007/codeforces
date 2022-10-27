#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		for (int i = 0; i < n; i ++)
			cin >> s[i];

		bool ok = true;
		for (int i = 0; i + 1 < n; i ++)
			for (int j = 0; j + 1 < m; j ++) {
				int sum = (s[i][j]=='1'?1:0) + (s[i+1][j]=='1'?1:0) + (s[i][j+1]=='1'?1:0) + (s[i+1][j+1]=='1'?1:0);
				if (sum == 3) ok = false;
			}
		cout << (ok?"YES":"NO") << "\n";
	}
}