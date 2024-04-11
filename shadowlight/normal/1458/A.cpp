#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector <ll> a(n), b(m);

	ll x = -1;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (x == -1) {
			x = a[i];
		} else {
			x = min(x, a[i]);
		}
	}
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		a[i] -= x;
		if (a[i]) {
			res = __gcd(res, a[i]);
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		cout << __gcd(x + b[i], res) << " ";
	}
	cout << "\n";

}