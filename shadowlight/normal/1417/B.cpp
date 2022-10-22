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
	int n, t;
	cin >> n >> t;
	vector <int> a(n);
	map <int, int> cnt;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	if (t % 2) {
		for (int i = 0; i < n; ++i) {
			if (a[i] % 2) {
				cout << "0 ";
			} else {
				cout << "1 ";
			}
		}
		cout << "\n";
		return;
	}
	map <int, int> col;
	for (auto [x, y] : cnt) {
		if (x == t / 2) continue;
		if (x > t / 2) {
			col[x] = 0;
		} else {
			col[x] = 1;
		}
	}
	int now = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == t / 2) {
			++now;
			if (2 * now <= cnt[t / 2]) {
				cout << "0 ";
			} else {
				cout << "1 ";
			}
		} else {
			cout << col[a[i]] << " ";
		}
	}
	cout << "\n";
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