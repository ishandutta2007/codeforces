

#include <bits/stdc++.h>

using namespace std;

int a[105], b[105], c[105], p[105];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int n, Tc;
	for (cin >> Tc; Tc--; ) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) cin >> c[i];
		p[0] = a[0];
		for (int i = 1; i < n - 1; i++) {
			if (p[i - 1] != a[i]) p[i] = a[i];
			else p[i] = b[i];
		}
		if (p[n - 2] != a[n - 1] && p[0] != a[n - 1]) p[n - 1] = a[n - 1];
		else if (p[n - 2] != b[n - 1] && p[0] != b[n - 1]) p[n - 1] = b[n - 1];
		else p[n - 1] = c[n - 1];
		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			cout << p[i];
		}
		cout << endl;
	}
	
	return 0;

}