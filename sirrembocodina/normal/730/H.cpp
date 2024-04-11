#include <iostream>
#include <algorithm>
#include <cstring>

#define fs first
#define sc second

using namespace std;

char s[110][110], ans[110];
bool used[110];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int len = 0;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		used[--x] = true;
		if (!i) {
			len = strlen(s[x]);
			for (int j = 0; j < len; ++j) {
				ans[j] = s[x][j];
			}
		} else {
			if (len != strlen(s[x])) {
				cout << "No\n";
				return 0;
			}
			for (int j = 0; j < len; ++j) {
				if (ans[j] != s[x][j]) {
					ans[j] = '?';
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		if (strlen(s[i]) != len) {
			continue;
		}
		bool ok = true;
		for (int j = 0; j < len; ++j) {
			if (ans[j] != '?' && ans[j] != s[i][j]) {
				ok= false;
			}
		}
		if (ok) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n" << ans << endl;
}