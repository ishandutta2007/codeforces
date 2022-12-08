#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string b;
	cin >> b;
	const int bil = 1000000000;
	int lmin = 0-bil;
	int lmax = bil;
	int rmin = 0-bil;
	int rmax = bil;
	for (int i = 4; i < n; i++) {
		int minprev = bil;
		int maxprev = 0-bil;
		bool p0 = true, p1 = true;
		for (int j = i-4; j <= i; j++) {
			minprev = min(minprev, a[j]);
			maxprev = max(maxprev, a[j]);
			if (j < i) {
				if (b[j] == '0') p1 = false;
				else p0 = true;
			}
		}


		if (b[i] == '0' && b[i-1] == '0' && p0) {
			lmax = min(lmax, maxprev);
		}
		if (b[i] == '0' && b[i-1] == '1' && p1) {
			rmax = min(rmax, minprev-1);
		}
		if (b[i] == '1' && b[i-1] == '0' && p0) {
			lmin = max(lmin, maxprev+1);
		}
		if (b[i] == '1' && b[i-1] == '1' && p1) {
			rmin = max(rmin, minprev);
		}
	}
	// cout << "rvals   " << rmin << "   " << rmax << endl;
	cout << lmin << " " << max(lmin, rmin) << endl;
	cin >> n;

}