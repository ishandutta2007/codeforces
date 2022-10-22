#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <ll> xs, ys;
	for (int i = 0; i < 2 * n; ++i) {
		int x, y;
		cin >> x >> y;
		if (x) {
			xs.pb(abs(x));
		} else {
			ys.pb(abs(y));
		}
	}
	sort(all(xs));
	sort(all(ys));
	db res = 0;
	for (int i = 0; i < n; ++i) {
		res += sqrtl(xs[i] * xs[i] + ys[i] * ys[i]);
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.precision(20);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}