#include <bits/stdc++.h>

using namespace std;

int Tc, N, n, x, a[200005];
#define MX 200005
typedef long long LL;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	for (cin >> Tc; Tc--; ) {
		cin >> n >> x;
		for (int i = 0; i < n; i ++) cin >> a[i];
		int nn = 0, mn, mx, rlt = 0;
		for (int i = 0; i < n; i ++) {
			if (nn == 0) mn = a[i], mx = a[i], nn ++;
			else {
				mn = min(mn, a[i]);
				mx = max(mx , a[i]);
				if (mx - mn > x * 2) nn = 1, mx = a[i], mn = a[i], rlt ++;
			}
		}
		cout << rlt << endl;
	}

	return 0;
}