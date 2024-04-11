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
	int a, b;
	cin >> a >> b;
	vector <int> q;
	string s;
	cin >> s;
	int now = 0;
	for (char c : s) {
		if (c == 'X') {
			if (now) q.pb(now);
			now = 0;
		} else {
			now++;
		}
	}
	if (now) q.pb(now);
	sort(q.rbegin(), q.rend());
	while (q.size() && q.back() < b) q.pop_back();
	if (q.size() >= 2 && q[1] >= 2 *  b) {
		cout << "NO\n";
		return;
	}
	if (!q.size()) {
		cout << "NO\n";
		return;
	}
	if (q.back() < a) {
		cout << "NO\n";
		return;
	}
	int cnt = (int) q.size() - 1;
	for (ll x = 0; x <= q[0] - a; x++) {
		ll y = q[0] - a - x;
		if (x >= b && x < a) continue;
		if (y >= b && y < a) continue;
		if (x >= 2 * b || y >= 2 * b) continue;
		if (x >= a && y >= a && cnt % 2 == 0) {
			cout << "YES\n";
			return;
		}
		if (x >= a && y >= a) continue;
		if (x < b && y < b && cnt % 2 == 0) {
			cout << "YES\n";
			return;
		}
		if (x < b && y < b) continue;
		if (cnt % 2 == 1) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}
}