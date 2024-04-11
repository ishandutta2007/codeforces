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
	int odd_min = INF, even_min = INF;	
	ll sum = 0;
	ll res = INF * (ll) INF;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (i % 2) {
			odd_min = min(odd_min, x);
		} else {
			even_min = min(even_min, x);
		}
		sum += x;
		int even = i / 2 + 1;
		int odd = (i + 1) - even;

		ll now = sum;
		now += (n - even) * (ll) even_min + (n - odd) * (ll) odd_min;
		res = min(res, now);
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}