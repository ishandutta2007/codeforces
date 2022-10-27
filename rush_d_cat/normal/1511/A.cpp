#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		int n; cin >> n;
		vector<int> r(n), c(4, 0);
		for (int i = 0; i < n; i ++) {
			cin >> r[i]; c[r[i]] ++;
		}
		if (c[1] > 0) {
			cout << c[1] + c[3] << endl;
		} else {
			cout << c[3] << endl;
		}
	}
}