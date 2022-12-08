#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, a[500];
	long long sum;
	bool flag, flag1;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sum = 0;
		for (i = 0; i < n; ++i) {
			sum = sum + a[i] - i;
			if (sum < 0)
				break;
		}
		if (i == n)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}