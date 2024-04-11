#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector <int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int cnt = 0, last = -2;
	vector <ll> segs;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] <= n - k) {
			if (i && last != i - 1) {
				cnt++;
				segs.pb(1);
			} else if (segs.size()) {
				segs.back()++;
			}
			last = i;
		} else {
			sum += p[i];
		}
	}
	if (last == n - 1) {
		cnt--;
		segs.pop_back();
	}
	int res = 1;
	for (int x : segs) {
		res = res * (ll) (x + 1) % MOD;
	}
	cout << sum << " " << res << "\n";
}