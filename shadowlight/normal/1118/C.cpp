#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> cnt(1007, 0);
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	vector <vector <int> > all(n, vector <int> (n, 0));
	int a = n / 2 - 1, b = n / 2 - 1;
	bool mid = false;
	for (int i = 0; i < 1007; i++) {
		if (n % 2 == 0 && cnt[i] % 4) {
			cout << "NO\n";
			return 0;
		}
		if (cnt[i] % 2) {
			if (mid) {
				cout << "NO\n";
				return 0;
			}
			mid = true;
			all[n / 2][n / 2] = i;
			cnt[i]--;
		}
		if (cnt[i] % 4 == 2) {
			if (a == -1 && b == -1) {
				cout << "NO\n";
				return 0;
			}
			if (a == -1) {
				all[n / 2][b--] = i;
			} else {
				all[a--][n / 2] = i;
			}
			cnt[i] -= 2;
		}
	}
	if ((a + b) % 2) {
		cout << "NO\n";
		return 0;
	}
	int now = 0;
	for (int i = 0; i < 1007; i++) {
		while (cnt[i]) {
			if (n % 2 == 0 || (a == -1 && b == -1)) {
				all[now / (n / 2)][now % (n / 2)] = i;
				now++;
			} else {
				for (int j = 0; j < 2; j++) {
					if (a == -1) {
						all[n / 2][b--] = i;
					} else {
						all[a--][n / 2] = i;
					}
				}
			}
			cnt[i] -= 4;
			//cout << i << " " << cnt[i] << " " << now << "\n";
		}
	}
	for (int i = 0; i < n / 2 + (n % 2); i++) {
		for (int j = 0; j < n / 2 + (n % 2); j++) {
			all[i][n - j - 1] = all[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n / 2; j++) {
			all[n - j - 1][i] = all[j][i];
		}																																																																																																		
	}
	cout << "YES\n";																																																																																																																																																														
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << all[i][j] << " ";
		}
		cout << "\n";
	}
}