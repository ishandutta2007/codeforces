#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, i, j, k;
	vector<int> r;
	string s1, s2;
	cin >> n;
	cin >> s1;
	cin >> s2;
	r.clear();
	for (i = 0, j = 0; i < n; ++i) {
		if (s1[i] == '0')
			--j;
		else ++j;
		if (!j)
			r.push_back(i);
	}
	r.push_back(0);
	j = 0;
	int a, b;
	for (i = 0; i < r.size() - 1; ++i) {
		a = b = 0;
		for (; j <= r[i]; ++j) {
			if (s1[j] != s2[j])
				++a;
			else
				++b;
		}
		if (a && b) {
			cout << "NO" << endl;
			return;
		}
	}
	a = b = 0;
	for (j; j < n; ++j) {
		if (s1[j] != s2[j])
			++a;
		else
			++b;
	}
	if (a) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}