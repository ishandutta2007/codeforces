#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

map<pair<int, int>, int> M;
int a[200100];
int b[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, q;
	cin >> n;
	long long ans = 0;
	forn (i, n) {
		cin >> a[i];
		ans += a[i];
	}
	cin >> q;
	forn (i, q) {
		int x, y, z;
		cin >> x >> y >> z;
		--x;
		--z;
		if (M.find(make_pair(x, y)) != M.end()) {
			int t = M[make_pair(x, y)];
			if (t != -1) {
				M[make_pair(x, y)] = -1;
				if (b[t] <= a[t]) {
					ans++;
				}
				b[t]--;
			}
		}
		M[make_pair(x, y)] = z;
		if (z != -1) {
			b[z]++;
			if (b[z] <= a[z]) {
				ans--;
			}
		}
		cout << ans << endl;
	}
}