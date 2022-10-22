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
	vector <ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = -1, r = 40;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		ll sum = 0;
		for (int i = 0; i < mid; ++i) {
			sum += (1LL << i);
		}
		ll max_val = INF;
		bool can = true;
		for (int i = n - 1; i >= 0; i--) {
			if (max_val < a[i]) {
				can = false;
				break;
			}
			max_val = min(max_val, a[i] + sum);
		}
		if (can) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}