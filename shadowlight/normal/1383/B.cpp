#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int LOGN = 31;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> cnt(LOGN);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < LOGN; ++j) {
			if (a[i] & (1 << j)) {
				++cnt[j];
			}
		}
	}
	for (int j = LOGN - 1; j >= 0; --j) {
		if (cnt[j] % 2 == 0) continue;
		if ((cnt[j] % 4 == 1) || (n - cnt[j]) % 2) {
			cout << "WIN\n";
		} else {
			cout << "LOSE\n";
		}
		return;
	}
	cout << "DRAW\n";
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