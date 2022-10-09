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

int n;

vector<long long> x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    x.assign(n, 0);
    y.assign(n, 0);
	for (int i = 2; i < n; ++i) {
		cout << "1 1 2 " << i + 1 << endl;
		cin >> x[i];
		cout << "2 1 2 " << i + 1 << endl;
		int sgn;
		cin >> sgn;
		x[i] *= sgn;
	}
	int mn = 0, mx = 0;
	forn (i, n) {
		if (x[i] < x[mn]) {
			mn = i;
		}
		if (x[i] > x[mx]) {
			mx = i;
		}
	}
	vector<pair<long long, int> > a, b;
	forn (i, n) {
		if (i == mn || i == mx) {
			continue;
		}
		cout << "2 " << mn + 1 << " " << mx + 1 << " " << i + 1 << endl;
		cin >> y[i];
		if (y[i] > 0) {
			a.pb(make_pair(x[i], i));
		} else {
			b.pb(make_pair(x[i], i));
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> ans;
	ans.pb(mn);
	forn (i, b.size()) {
		ans.pb(b[i].sc);
	}
	ans.pb(mx);
	for (int i = int(a.size()) - 1; i >= 0; --i) {
		ans.pb(a[i].sc);
	}
	cout << "0 ";
	bool was = false;
	forn (i, n) {
		if (ans[i] == 0) {
			was = true;
		}
		if (!was) {
			continue;
		}
		cout << ans[i] + 1 << " ";
	}
	forn (i, n) {
		if (ans[i] == 0) {
			break;
		}
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
}