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
	ll n, m;
	cin >> n >> m;
	ll f = m * 10;
	ll sum = 0;
	for (ll i = 0; i < 10; i++) {
		sum += (m * i) % 10;
	}
	ll d = n / (10 * m);
	ll res = sum * d;
	ll now = d * (10 * m);
	while (now <= n) {
		res += now % 10;
		now += m;
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
	for (int i = 0; i < t; i++) {
		solve();
	}
}