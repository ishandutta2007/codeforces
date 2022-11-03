#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

bool Check(int *a, int n, int k) {
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}
	if (sum % k) {
		return false;
	}

	int p = sum / k, q = 0;
	int last = -1;
	int t = 0;

	for (int i = 0; i < n - 1; ++i) {
		q += a[i];
		if (q == p) {
			q = 0;
			b[t++] = i - last;
			last = i;
		}
		if (q > p) {
			return false;
		}
	}

	if (q + a[n - 1] == p) {
		b[t++] = n - 1 - last;
		assert(t == k);
		return true;
	} else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	int n, k;

	while (cin >> n >> k) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		bool ok = Check(a, n, k);

		if (ok) {
			cout << "Yes" << endl;
			for (int i = 0; i < k; ++i) {
				cout << b[i] << ' ';
			}
			cout << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}