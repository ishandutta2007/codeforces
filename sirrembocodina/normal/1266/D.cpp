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

pair<long long, int> d[100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn (i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		d[a].fs -= c;
		d[b].fs += c;
	}
	forn (i, n) {
		d[i].sc = i;
	}
	sort(d, d + n);
	vector<pair<pair<int, int>, long long> > ans;
	int i = 0, j = n - 1;
	while (i < j && d[i].fs < 0) {
		if (-d[i].fs == d[j].fs) {
			ans.pb(make_pair(make_pair(d[i].sc, d[j].sc), d[j].fs));
			++i;
			--j;
		} else if (-d[i].fs < d[j].fs) {
			ans.pb(make_pair(make_pair(d[i].sc, d[j].sc), -d[i].fs));
			d[j].fs -= -d[i].fs;
			++i;
		} else {
			ans.pb(make_pair(make_pair(d[i].sc, d[j].sc), d[j].fs));
			d[i].fs += d[j].fs;
			--j;
		}
	}
	cout << ans.size() << endl;
	forn (i, ans.size()) {
		cout << ans[i].fs.fs + 1 << ' ' << ans[i].fs.sc + 1 << ' ' << ans[i].sc << endl;
	}
}