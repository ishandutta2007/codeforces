#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n;
		string s;
		cin >> n >> s;
		// 111111011
		// 111111
		// 1111110

		// 11101111
		int las = -1;
		for (int i = n - 1; i >= 0; i --) 
			if (s[i] == '0') {
				las = i; break;
			}

		if (las == -1) {
			cout << 1 << " " << n-1 << " " << 2 << " " << n << "\n";
		} else {
			if (las >= (n + 1) / 2) {
				cout << 1 << " " << (las + 1) << " " << 1 << " " << las << "\n";
			} else {
				cout << (las + 1) << " " << n << " " << (las+2) << " " << n << "\n";
			}
		}
	}
}