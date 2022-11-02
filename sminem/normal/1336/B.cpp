#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sq(ll x) { return x*x; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int s[3];
		for (int i=0; i<3; i++)
			cin >> s[i];
		vector<int> a[3];
		for (int i=0; i<3; i++) {
			for (int j=0; j<s[i]; j++) {
				int x;
				cin >> x;
				a[i].push_back(x);
			}
			sort(begin(a[i]), end(a[i]));
		}

		int p[3] = {0, 1, 2};
		ll sol = 4e18;
		do {
			for (int x : a[p[0]]) {
				auto it1 = upper_bound(begin(a[p[1]]), end(a[p[1]]), x);
				auto it2 = lower_bound(begin(a[p[2]]), end(a[p[2]]), x);
				if (it1 != begin(a[p[1]]))
					--it1;
				else
					continue;

				if (it2 != end(a[p[2]])) {
					sol = min(sol, sq(x-*it1) + sq(x-*it2) + sq(*it1-*it2));
				}
				
			}
		} while (next_permutation(p, p+3));

		cout << sol << '\n';
	}
}