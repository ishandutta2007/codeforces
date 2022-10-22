#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 1e9 + 7;
const int M = 60;

void add(int& x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

void solve() {
	int n;
	cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	} 

	vector <int> cnt(M, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < M; ++j) {
			if (a[i] & (1LL << j)) {
				++cnt[j];
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int vala = 0, valb = 0;

		int tet = 1;
		for (int d = 0; d < M; ++d) {
			if (a[i] & (1LL << d)) {
				add(vala, tet * (ll)cnt[d] % MOD);
				add(valb, tet * (ll)n % MOD);
			} else {
				add(valb, tet * (ll) cnt[d] % MOD);
			}
			tet = tet * 2 % MOD;
		}
		//cout << vala << " " << valb << "\n";
		add(res, vala * (ll) valb % MOD);
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}