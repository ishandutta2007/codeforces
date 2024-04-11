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
	ll n;
	cin >> n;
	--n;
	ll d = n % 3;
	ll res = 0;

	n /= 3;

	//cout << "N: " << n << endl;
	ll cnt = 1;
	ll ss = 0;
	while (ss + cnt <= n) {
		ss += cnt;
		cnt *= 4;
	}
	res += cnt * (d + 1);
	n -= ss;

	ll now = 1;
	while (now <= n) {
		now *= 4;
	}

	vector <vector <int> > ps = {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}};

	while (now > 1) {
		now /= 4;
		if (now > n) continue;
		int num = n / now;
		assert(0 < num && num < 4);
		res += ps[num - 1][d] * now;
		n -= num * now;
	}

	cout << res << endl;
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}