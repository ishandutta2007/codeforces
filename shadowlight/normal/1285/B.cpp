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
	vector <int> a(n);
	ll sum = 0;
	bool bad = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (sum <= 0) {
			bad = true;
		}
	}
	sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += a[i];
		if (sum <= 0) {
			bad = true;
		}
	}
	cout << (bad ? "NO\n" : "YES\n");
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
	for (int i = 0; i < t; i++) {
		solve();
	}
}