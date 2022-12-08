#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pii> shows;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		shows.push_back(pii(l, r));
	}
	sort(shows.begin(), shows.end());
	int oend = -1;
	int tend = -1;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		l = shows[i].first;
		r = shows[i].second;
		if (l > oend) {
			oend = r;
		}
		else if (l > tend) {
			tend = r;
		}
		else ok = false;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	cin >> n;
}