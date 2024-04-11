#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[1005], b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];

	for (int i=1; i<=n; i++) {
		if (a[i] == 1 || b[i] == 1)
			return cout << -1, 0;
	}

	b[n+1] = b[1];
	a[n+1] = a[1];

	int rep = 100;
	double lo = 0.0, hi = 1.1e9;
	
	while (rep--) {
		double mid = (lo + hi) / 2;
		double f = mid;

		bool ok = true;

		for (int i=1; i<=n; i++) {
			// take off i, land i+1
			double skidaj = (m + f) / a[i];
			if (skidaj > f) {
				ok = false;
				break;
			}
			f -= skidaj;

			skidaj = (m + f) / b[i+1];
			if (skidaj > f) {
				ok = false;
				break;
			}
			f -= skidaj;
		}

		if (ok) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

	cout.precision(20);
	cout << fixed << lo << '\n';
}