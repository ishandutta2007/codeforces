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

	int n, d, m;
	cin >> n >> d >> m;
	vector <int> a, b;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x <= m) {
			b.pb(x);
		} else {
			a.pb(x);
		}
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	vector <ll> prefb(b.size() + 1, 0);
	for (int i = 0; i < b.size(); ++i) {
		prefb[i + 1] = prefb[i] + b[i];
	}

	ll res = 0;
	ll prefa = 0;
	for (int i = 0; i <= a.size(); ++i) {
		ll block_count = max((i - 1) * (ll) d, 0LL);
		block_count -= (a.size() - i);
		block_count = max(block_count, 0LL);
		ll count = (ll) b.size() - block_count;
		if (count < 0) continue;

		ll now = prefa + prefb[count];
		//cout << i << " " << now << endl;

		res = max(res, now);

		if (i < a.size()) {
			prefa += a[i];
		}
	}

	cout << res << endl;

}