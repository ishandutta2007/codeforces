#include <iostream>
#include <vector>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(X) X.begin(), X.end()
#define sz(X) ((int)X.size())

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vl;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, s;
	cin >> n >> m >> k >> s;

	vi d_cost(n);
	for (int i = 0; i < n; i++) cin >> d_cost[i];

	vi p_cost(n);
	for (int i = 0; i < n; i++) cin >> p_cost[i];

	vpii d_gad, p_gad;
	for (int i = 0; i < m; i++) {
		int type, cost;
		cin >> type >> cost;
		if (type == 1) d_gad.eb(cost, i + 1);
		else p_gad.eb(cost, i + 1);
	}

	sort(all(d_gad));
	sort(all(p_gad));

	vl d_pref(1), p_pref(1);
	for (auto el : d_gad) {
		d_pref.pb(d_pref.back() + el.first);
	}
	for (auto el : p_gad) {
		p_pref.pb(p_pref.back() + el.first);
	}

	int l = 0, r = n + 1;
	while (r - l > 1) {
		int med = (l + r) / 2; // Can you do it in 'med' days?
		int d_low = d_cost[0], p_low = p_cost[0];
		for (int i = 1; i < med; i++) d_low = min(d_low, d_cost[i]), p_low = min(p_low, p_cost[i]);
		bool can_do = false;
		for (int i = 0; i <= k && !can_do; i++) {
			if (sz(d_pref) > i && sz(p_pref) > k - i && d_pref[i] * d_low + p_pref[k - i] * p_low <= s) can_do = true;
		}
		if (can_do) r = med;
		else l = med;
	}

	if (r == n + 1) cout << -1 << endl;
	else {
		int d_pos = 0, p_pos = 0;
		for (int i = 1; i < r; i++) {
			if (d_cost[i] < d_cost[d_pos]) d_pos = i;
			if (p_cost[i] < p_cost[p_pos]) p_pos = i;
		}
		int partn;
		for (int i = 0; i <= k; i++) {
			if (sz(d_pref) > i && sz(p_pref) > k - i && d_pref[i] * (ll)d_cost[d_pos] + p_pref[k - i] * (ll)p_cost[p_pos] <= s) {
				partn = i;
				break;
			}
		}
		cout << r << endl;
		for (int i = 0; i < partn; i++) cout << d_gad[i].second << ' ' << d_pos + 1 << endl;
		for (int i = 0; i < k - partn; i++) cout << p_gad[i].second << ' ' << p_pos + 1 << endl;
	}
}