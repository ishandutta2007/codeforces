#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 1e5 + 7;

ll a, m, g;
ll res = 0;

void solve() {
	cin >> a >> m;
	g = __gcd(a, m);
	a /= g, m /= g;
	ll d = m;
	res = m;
	for (int i = 2; i < MAXN; i++) {
		int cnt = 0;
		while (d % i == 0) {
			d /= i;
			cnt++;
		}
		if (cnt) {
			res /= i;
			res *= i - 1; 
		}
	}
	if (d != 1) {
		res /= d;
		res *= d - 1;
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}