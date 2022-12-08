#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		bool ok = false;
		for (int j = 0; j <= 100; j++) {
			int val = cur-j*3;
			if (val >= 0 && val%7 == 0) ok = true;
		}
		if (ok) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	cin >> n;
}