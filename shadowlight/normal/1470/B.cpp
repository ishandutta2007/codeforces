#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e6 + 7;
int d[N];
vector <int> p;

void sieve() {
	fill_n(d, N, -1);
	for (int i = 2; i < N; ++i) {
		if (d[i] == -1) {
			p.pb(i);
			d[i] = p.size() - 1;
		}
		for (int j = 0; j <= d[i]; ++j) {
			if (p[j] * (ll)i >= N) break;
			d[p[j] * i] = j;
		}
	}
}

void solve() {
	int n;
	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];

		int ww = 1;
		while (a[i] > 1) {
			int x = p[d[a[i]]];
			int cnt = 0;
			while (a[i] % x == 0) {
				++cnt;
				a[i] /= x;
			}
			if (cnt % 2) {
				ww *= x;
			}
		}
		a[i] = ww;
	}

	map <int, int> cnt;
	
	for (int i = 0; i < n; ++i) {
		++cnt[a[i]];
	}

	int res0 = 0, res1 = 0;

	map <int, int> cnt2;
	for (auto [x, y] : cnt) {
		res0 = max(res0, y);
		if (y % 2 == 0) {
			cnt2[1] += y;
		} else {
			cnt2[x] += y;
			res1 = max(res1, cnt2[x]);
		}
	}
	res1 = max(res1, cnt2[1]);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll w;
		cin >> w;
		if (w == 0) {
			cout << res0 << "\n";
		} else {
			cout << res1 << "\n";
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
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