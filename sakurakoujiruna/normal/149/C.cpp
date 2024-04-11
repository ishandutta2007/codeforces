#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;
const int N = (int)1e5 + 11;
int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	vector <int> vl, vr;
	int sl = 0, sr = 0;
	for(int i = 0; i + 1 < n; i += 2) {
		if(ll(sr - sl) * (a[i + 1] - a[i]) <= 0) {
			vl.pb(i);
			vr.pb(i + 1);
			sl += a[i];
			sr += a[i + 1];
		} else {
			vl.pb(i + 1);
			vr.pb(i);
			sl += a[i + 1];
			sr += a[i];
		}
	}
	if(n & 1) {
		(sl < sr ? vl : vr).pb(n - 1);
	}
	cout << vl.size() << '\n';
	for(int x : vl) cout << x + 1 << ' '; cout << '\n';
	cout << vr.size() << '\n';
	for(int x : vr) cout << x + 1 << ' '; cout << '\n';
	return 0;
}