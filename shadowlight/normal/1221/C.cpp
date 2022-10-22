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
	ll c, m, x;
	cin >> c >> m >> x;
	ll l = 0, r = 1e9 + 7;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (c < mid || m < mid) {
			r = mid;
			continue;
		}
		ll d = x + (c - mid) + (m - mid);
		if (d >= mid) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}