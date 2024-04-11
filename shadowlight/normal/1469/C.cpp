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
	vector <int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	int l = h[0], r = h[0];
	for (int i = 1; i < n; ++i) {
		int lt = h[i], rt = h[i] + k - 1;
		l -= k - 1;
		r += k - 1;
		//cout << l << " " << r << " " << lt << " " << rt << "\n";
		l = max(l, lt);
		r = min(r, rt);
		if (r < l) {
			cout << "NO\n";
			return;
		}
	}
	if (l > h.back()) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}