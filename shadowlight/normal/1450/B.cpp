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
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}

	for (int i = 0; i < n; ++i) {
		bool can = true;
		for (int j = 0; j < n; ++j) {
			int x = abs(a[i].x - a[j].x);
			int y = abs(a[i].y - a[j].y);
			if (x + y > k) {
				can = false;
			}
		}
		if (can) {
			cout << "1\n";
			return;
		}
	}
	cout << "-1\n";
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