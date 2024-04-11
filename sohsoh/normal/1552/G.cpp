#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 40 + 10;

int n, k;
vector<int> vec[MAXN];
vector<ll> mask_vec[2];
ll t_mask;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int t;
			cin >> t;
			vec[i].push_back(t - 1);
		}
	}

	mask_vec[0] = {0};
	for (int j = 1; j <= k; j++) {
		int ind = j & 1;
		mask_vec[ind].clear();
		ll mask_i = 0;
	
		for (int e : vec[j])
			mask_i ^= (1ll << e);

		int sz = vec[j].size();
		for (ll mask : mask_vec[ind ^ 1]) {
			int cnt0 = 0, cnt1 = 0, f = 0;
			f = sz - __builtin_popcountll(mask_i & t_mask);
			cnt1 = __builtin_popcountll(mask & mask_i);
			cnt0 = sz - f - cnt1;

			mask = (mask | mask_i) ^ mask_i;
			for (int i = sz; i >= cnt0; i--) {
				if (i <= cnt0 + f) mask_vec[ind].push_back(mask);
				if (i) mask ^= (1ll << vec[j][i - 1]);
			}
		}
		
		t_mask |= mask_i;
	}

	for (ll e : mask_vec[k & 1]) {
		bool b = false;
		for (int i = 0; i < n; i++) {
			if (b && ((e & (1ll << i)) == 0 || (t_mask & (1ll << i)) == 0)) return cout << "REJECTED" << endl, 0;
			if ((e & (1ll << i)) || (t_mask & (1ll << i)) == 0) b = true;
		}
	}

	cout << "ACCEPTED" << endl;
	return 0;
}