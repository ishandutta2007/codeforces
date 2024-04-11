#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e7 + 7;

int d[N];
vector <int> ps;

void sieve() {
	fill_n(d, N, -1);
	for (int i = 2; i < N; ++i) {
		if (d[i] == -1) {
			ps.pb(i);
			d[i] = ps.size() - 1;
		}
		for (int j = 0; j <= d[i]; ++j) {
			if (ps[j] * (ll) i >= N) break;
			d[ps[j] * i] = j;
		}
	}
}

void solve() {
	int cx, dx, x;
	cin >> cx >> dx >> x;

	ll res = 0;

	for (int i = 1; i * i <= x; ++i) {
		if (x % i) continue;
		int g = i;
		for (int it = 0; it < 2; ++it) {
			int val = x / g;
			if ((val + dx) % cx == 0) {
				int mlt = (val + dx) / cx;
				int total = 0;
				while (mlt != 1) {
					int val = ps[d[mlt]];
					while (mlt % val == 0) {
						mlt /= val;
					}
					++total;
				}
				res += (1 << total);
			}
			if (g * g != x) {
				g = x / g;
			} else {
				break;
			}
		}
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

	sieve();

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}