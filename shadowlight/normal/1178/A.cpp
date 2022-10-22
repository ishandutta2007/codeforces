#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e4 + 7;
const int INF = 1e9 + 7;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n);
	int sum = 0, x = 0;
	vector <int> res;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (i == 0 || a[0] >= 2 * a[i]) {
			x += a[i];
			res.push_back(i);
		}
	}
	if (2 * x > sum) {
		cout << res.size() << "\n";
		for (int y : res) {
			cout << y + 1 << " ";
		}
		cout << "\n";
	} else {
		cout << "0\n";
	}
}