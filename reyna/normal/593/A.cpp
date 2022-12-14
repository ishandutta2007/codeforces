//In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 149;

string s[N];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int res = 0;
	for (int i = 'a'; i <= 'z'; i++)
		for (int j = i + 1; j <= 'z'; j++) {
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				bool flag = 1;
				for (int r = 0; r < (int) s[k].size(); r++) {
					if (s[k][r] != i && s[k][r] != j) {
						flag = 0;
					}
				}
				if (flag) {
					cnt += (int) s[k].size();
				}
			}
			res = max(res, cnt);
		}
	cout << res << endl;
	return 0;
}