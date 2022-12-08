#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k, i;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		a.clear();
		for (i = (k + 1) / 2; i <= k - 1; ++i)
			a.push_back(i);
		for (i = k + 1; i <= n; ++i)
			a.push_back(i);
		cout << a.size() << endl;
		for (i = 0; i < a.size(); ++i)
			cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}