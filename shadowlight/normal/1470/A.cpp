#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 1e18 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	sort(all(a));
	vector <int> b(m);
	for (int j = 0; j < m; ++j) {
		cin >> b[j];
	}

	ll sum = 0;
	ll res = INF;

	for (int i = 0; i < n; ++i) {
		sum += b[a[i]];
	}
	res = min(res, sum);
	ll sum2 = 0;
	for (int i = 0; i < min(n, m); ++i) {
		sum -= b[a[n - 1 - i]];
		sum2 += b[i];
		res = min(res, sum + sum2);
		//cout << i << " " << sum << " " <<
	}
	cout << res << "\n";
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