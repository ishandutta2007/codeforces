#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, t;
	cin >> n >> m;
	n--;
	if (m == 0) {
		if (n == 0)
			cout << 1;
		else
			cout << -1;
		return 0;
	}
	vector<int> num(100, -1);
	for (int i = 0; i < m; i++) {
		cin >> t;
		cin >> num[--t];
	}
	vector<int> ans;
	for (int i = 1; i < 102; i++) {
		bool f = 1;
		int fl = 0;
		for (int j = 0; j < 100; j++) {
			if (j % i == 0)
				fl++;
			if (num[j] != -1 && num[j] != fl) {
				f = 0;
				break;
			}
		}
		if (f)
			ans.push_back(i);
	}
	int nn = -1;
	for (int i : ans) {
		t = n / i;
		if (nn == -1)
			nn = t;
		else if (nn != t) {
			cout << -1;
			return 0;
		}
	}
	cout << nn + 1;
}