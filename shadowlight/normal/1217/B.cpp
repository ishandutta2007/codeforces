#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	set <int> a, b;
	for (int i = 0; i < n; i++) {
		int d, h;
		cin >> d >> h;
		a.insert(d);
		b.insert(h - d);
	}
	if (*a.rbegin() < x && *b.begin() >= 0) {
		cout << "-1\n";
		return;
	}
	int t = (x - *a.rbegin());
	if (t <= 0) {
		cout << "1\n";
		return;
	}
	int res = (t - 1) / abs(*b.begin()) + 1;
	if (res * abs(*b.begin()) < x) res++;
	cout << res << "\n";
}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}