#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <int> pref(n + 1, INF), suf(n + 1, INF);
	pref[0] = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= pref[i]) break;
		pref[i + 1] = pref[i] + 1;
	}
	suf[n] = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= suf[i + 1]) break;
		suf[i] = suf[i + 1] + 1;
	}
	for (int i = 0; i < n; i++) {
		if (pref[i] < a[i] && a[i] > suf[i + 1]) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main(){
#ifdef LOCAL
	freopen("K_input.txt", "r", stdin);
	//freopen("K_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}