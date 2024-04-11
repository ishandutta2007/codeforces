#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int LOGN = 30;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector <vector <int> > groups;
	vector <int> total(n, 0);
	iota(all(total), 0);
	groups.pb(total);

	ll res = 0, resx = 0;

	for (int bit = LOGN - 1; bit >= 0; --bit) {
		ll inv0 = 0, inv1 = 0;
		vector<vector <int>> new_groups;
		for (auto& group : groups) {
			vector <int> gra, grb;
			int sz = group.size();
			
			for (int x : group) {
				if (a[x] & (1 << bit)) {
					gra.pb(x);
				} else {
					grb.pb(x);
				}
			}

			ll total_inv = (ll) gra.size() * grb.size();
			ll inv1_now = 0;
			int it = 0;
			for (int x : gra) {
				while (it < grb.size() && grb[it] < x) {
					++it;
				}
				inv1_now += it;
			}
			inv1 += inv1_now;
			inv0 += total_inv - inv1_now; 
			if (gra.size()) {
				new_groups.pb(gra);
			}
			if (grb.size()) {
				new_groups.pb(grb);
			}
		}
		//cout << (1 << bit) << " " << inv0 << " " << inv1 << endl;
		groups = new_groups;
		if (inv1 < inv0) {
			res += inv1;
			resx += (1 << bit);
		} else {
			res += inv0;
		}
	}
	cout << res << " " << resx << "\n";

}