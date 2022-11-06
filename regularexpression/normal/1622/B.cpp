#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			--p[i];
		}
		string s;
		cin >> s;
		vector<int> a0, a1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				a0.push_back(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				a1.push_back(i);
			}
		}
		vector<int> q(n);
		sort(a0.begin(), a0.end(), [&](int i, int j) {
			return p[i] < p[j];
		});
		int t = 0;
		for (int i : a0) {
			q[i] = t++;
		}
		sort(a1.begin(), a1.end(), [&](int i, int j) {
			return p[i] < p[j];
		});
		for (int i : a1) {
			q[i] = t++;
		}
		for (int i = 0; i < n; ++i) {
			cout << q[i] + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}