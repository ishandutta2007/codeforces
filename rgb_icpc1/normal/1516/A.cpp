#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;
int a[105];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n - 1 && k; i++) {
			if (a[i] <= k) {
				a[n - 1] += a[i];
				k -= a[i];
				a[i] = 0;
			}
			else {
				a[i] -= k;
				a[n - 1] += k;
				k = 0;
			}
		}
		for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
 	}

	return 0;

}