#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
const ll INF = (ll) 1e18 + 7;
 
int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
 
	if (!k) {
		vector <int> a(n);
		for (int &x : a) {
			cin >> x;
		}
		sort(all(a));
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += i * (ll) a[i];
		}
		cout << sum << "\n";
		return 0;
	}
 
	vector <int> a;
	vector <int> b;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x >= 0) {
			sum += x;
			b.pb(x);
		} else {
			a.pb(x);
		}
	}
	sort(all(a));
	sort(all(b));
 
	int m = a.size();
	vector <ll> pref(m + 1, 0);
	for (int i = 0; i < m; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
	vector <ll> prefm(m + 1, 0);
	for (int i = 0; i < m; ++i) {
		prefm[i + 1] = prefm[i] + a[i] * (ll) i;
	}
 
	vector <ll> lvls_sum(m + 1, 0);
	for (int i = 0; i < m; ++i) {
		lvls_sum[i + 1] = lvls_sum[i];
		int have = i * (k + 1);
		int nxt = have + (k + 1);
		if (nxt > m) break;
		lvls_sum[i + 1] += i * (pref[nxt] - pref[have]);
	}
 
 
	int d = m / (k + 1);
	if (m % (k + 1)) {
		++d;
	}
 
	ll res = -INF;
 
	ll positive_add = 0;
	for (ll i = 0; i < (int) b.size(); ++i) {
		positive_add += (d + i) * (ll) b[i];
	}
 
	while (d <= m) {
		int cnt = m - d;
 
		int lvl = cnt / k;
		int additional_count = cnt % k;
		int have = lvl * (k + 1);
 
		ll now = positive_add;
		now += lvls_sum[lvl];
		//cout << lvl << " " << lvls_sum[lvl] << " " << lvl * (pref[have + additional_count + 1] - pref[have + 1]) << "\n";
		now += lvl * (pref[have + additional_count] - pref[have]);
 
		int dd = (d - lvl);
		int l = m - dd, r = m;
 
		now += (prefm[r] - prefm[l]) - (pref[r] - pref[l]) * (l - lvl);
 
		//cout << d << " " << now << "\n";

		//cout << d << " " << m << " " << l << " " << r << " " << prefm[r] - prefm[l] << " " << now << endl;

		res = max(res, now);
 
		++d;
		positive_add += sum;
	}
 
	cout << res << "\n";
 
}