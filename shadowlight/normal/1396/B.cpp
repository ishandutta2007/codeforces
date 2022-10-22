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
	int sum = 0;
	vector <int> a;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sum += x;
		a.pb(x);
	}
	if (sum % 2) {
		cout << "T\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (2 * a[i] > sum) {
			cout << "T\n";
			return;
		}
	}
	cout << "HL\n";
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