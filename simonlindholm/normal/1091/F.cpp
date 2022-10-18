#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vector<ll> len(N);
	rep(i,0,N) cin >> len[i];
	string types;
	cin >> types;
	int chargeUpCost = 5;
	vector<pair<ll, ll>> stamina;
	ll time = 0;
	ll res = 0;
	rep(i,0,N) {
		if (types[i] == 'W') chargeUpCost = 3;
		if (types[i] == 'L') {
			ll le = len[i];
			res += le;
			while (le > 0) {
				if (stamina.empty()) {
					res += chargeUpCost * le;
					le = 0;
					break;
				}

				auto pa = stamina.back();
				stamina.pop_back();
				if (pa.second - pa.first <= le) {
					le -= pa.second - pa.first;
					continue;
				}

				pa.second -= le;
				le = 0;
				stamina.push_back(pa);
			}
		} else {
			stamina.push_back({time, time + len[i]});
		}
		time += len[i];
	}

	for (char T : "GW") if (T) {
		time = 0;
		vector<pair<ll, ll>> oldStamina = stamina;
		stamina.clear();
		int j = 0;
		rep(i,0,N) {
			while (j < sz(oldStamina) && oldStamina[j].first <= time) {
				stamina.push_back(oldStamina[j]);
				j++;
			}

			if (types[i] == T) {
				ll le = len[i];
				res += le * (T == 'G' ? 5 : 3);
				le *= 2;
				while (le > 0 && !stamina.empty()) {
					auto pa = stamina.back();
					stamina.pop_back();
					ll ivlen = pa.second - pa.first;
					if (ivlen <= le) {
						le -= ivlen;
						// res -= (ivlen / 2) * 5;
						// res += (ivlen / 2);
						res -= ivlen * (T == 'G' ? 2 : 1);
						continue;
					}

					res -= le * 2;
					pa.second -= le;
					le = 0;
					stamina.push_back(pa);
				}
			}
			time += len[i];
		}
	}

	cout << res << endl;

	exit(0);
}