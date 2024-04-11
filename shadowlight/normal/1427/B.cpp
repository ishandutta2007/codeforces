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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int pr = -1;

	vector <int> a;
	int segs = 0;
	int ws = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'W' && s[i + 1] == 'L') {
			pr = i + 1;
			++segs;
		}
		if (s[i] == 'L' && s[i + 1] == 'W') {
			if (pr != -1) {
				a.pb(i - pr + 1);
			}
		}
		if (s[i] == 'W') {
			++ws;
		}
	}
	sort(all(a));

	if (s[n - 1] == 'W') {
		++segs;
		++ws;
	}
	if (ws + k >= n) {
		cout << 2 * n - 1 << "\n";
		return;
	}
	if (!ws) {
		cout << max(2 * k - 1, 0) << "\n";
		return;
	}
	for (int x : a) {
		if (x <= k) {
			--segs;
			k -= x;
			ws += x;
		} else {
			break;
		}
	}
	cout << 2 * (ws + k) - segs << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}