#include <bits/stdc++.h>

using namespace std;

string s[100005];
string u[100005];
int c[30];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> u[i];
	}
	string ans;
	for (int i = 0; i < m; ++i) {
		memset(c, 0, sizeof c);
		for (int j = 0; j < n; ++j) {
			++c[s[j][i] - 'a'];
		}
		for (int j = 0; j < n - 1; ++j) {
			--c[u[j][i] - 'a'];
		}
		for (int j = 0; j < 26; ++j) {
			if (c[j]) {
				ans += (char) ('a' + j);
				break;
			}
		}
	}
	cout << ans << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}