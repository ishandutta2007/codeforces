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
	vector <ll> a;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a.pb(x);
	}
	sort(all(a));
	bool was = false;
	for (int i = n - 2; i >= 0, k > 0; --i, --k) {
		a[n - 1] += a[i];
	}
	cout << a[n - 1] << "\n";
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