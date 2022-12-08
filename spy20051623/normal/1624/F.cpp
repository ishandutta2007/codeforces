#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int t = 0, s = 0;
	for (int i = 9; i >= 0; --i) {
		if (1 << i >= n) continue;
		int num = (n * 100 + t - (1 << i)) % n;
		if (num) {
			cout << "+ " << num << endl;
			int k;
			cin >> k;
			if (k == s) t = 1 << i;
			else t = 0;
			s = k;
		} else {
			t = 1 << i;
		}
	}
	cout << "! " << s * n + (n - t) % n << endl;
	return 0;
}