#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define rep(i,n) for (int i = 0; i < (int)n; ++i)

int main() {
	int t; cin >> t;
	while (t--) {
		int d;
		vi f(7);
		cin >> d;
		int s = 0;

		rep(i, 7) {
			cin >> f[i];
			s += f[i];
		}

		int ret = 1e9;

		rep(i, 7) { //start
			int w = d / s;
			if (d % s == 0) --w;
			int rem = d - w * s;
			w *= 7;

			int p = i;
			while (rem) {
				++w;
				if (f[p]) {
					--rem;
				}
				p++;
				if (p == 7) p = 0;
			}
			ret = min(ret, w);
		}

		cout << ret << endl;
	}

	return 0;
}