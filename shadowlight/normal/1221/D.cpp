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
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	vector <vector <ll> > res(n, vector <ll> (3, INF));
	res[0][1] = b[0], res[0][2] = 2 * b[0];
	res[0][0] = 0;
	for (ll i = 1; i < n; i++) {
		for (ll dw = 0; dw < 3; dw++) {
			for (ll du = 0; du < 3; du++) {
				if (a[i - 1] + dw == a[i] + du) continue;
				res[i][du] = min(res[i][du], res[i - 1][dw] + du * b[i]);
			}
		}
	}
	ll mn = INF;
	for (ll i = 0; i < 3; i++) {
		mn = min(res[n - 1][i], mn);
	}
	cout << mn << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}

}