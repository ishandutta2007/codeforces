#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i];

		vector<bool> flag(n, true);
		for (int i = 0; i < n; i ++) {
			if (i < x && n - 1 - i < x) flag[i] = false;
		}
		vector<int> tmp;
		for (int i = 0; i < n; i ++) if (flag[i]) tmp.emplace_back(a[i]);
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		for (int i = 0; i < n; i ++) {
			if (flag[i] == true) {
				a[i] = tmp.back(); tmp.pop_back();
			}
		}
		bool ok = true;
		for (int i = 0; i + 1 < a.size(); i ++) if (a[i] > a[i+1]) ok = false;
		cout << (ok?"YES":"NO") << "\n";
	}
} 
/*
2x > n
*/