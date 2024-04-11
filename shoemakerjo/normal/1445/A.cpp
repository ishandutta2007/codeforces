#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int maxn = 1010;
int n, x;
vector<int> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cin >> n >> x;
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		a.clear();
		b.clear();
		int cur;
		for (int i = 0; i < n; i++) {
			cin >> cur;
			a.push_back(cur);
		}
		for (int i = 0; i < n; i++) {
			cin >> cur;
			b.push_back(cur);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] + b[i] > x) ok = false;
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

}