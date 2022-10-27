#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isp(int x) {
	if (x == 1) return 0;
	if (x == 2) return 1;
	for (int i = 2; i < x; i ++) if (x % i == 0) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int k; string s;
		cin >> k >> s;
		// 1,4,6,8,9
		bool ok = 0;

		for (int i = 0; i < k; i ++) {
			if (ok) break;
			int x = s[i] - '0';
			if (x > 0) {
				if (! isp(x)) {
					cout << 1 << "\n";
					cout << x << "\n";
					ok = true; 
					break;
				}
			}	
		}

		for (int i = 0; i < k; i ++) {
			for (int j = i + 1; j < k; j ++) {
				if (ok) break;
				int x = 10*(s[i] - '0') + (s[j]-'0');
				if (x > 0) {
					if (! isp(x)) {
						cout << 2 << "\n";
						cout << x << "\n";
						ok = true; 
						break;
					}
				}	
			}
		}

		for (int i = 0; i < k; i ++) {
			for (int j = i + 1; j < k; j ++) {
				for (int y = j + 1; j < k; j ++) {
					if (ok) break;
					int x = 100*(s[i] - '0') + 10*(s[j]-'0') + (s[y]-'0');
					if (x > 0) {
						if (! isp(x)) {
							cout << 3 << "\n";
							cout << x << "\n";
							ok = true; 
							break;
						}
					}	
				}
			}
		}
	}
}