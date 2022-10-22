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
		vector <int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int cnt = 0;
		int res = n;
		for (int c = 1; c <= 100; ++c) {
			int cur = 0, now = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] == c && !now) continue;
				if (!now) {
					++cur;
				}
				++now;
				if (now == k) {
					now = 0;
				}
			}
			res = min(res, cur);
		}
		cout << res << "\n";
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