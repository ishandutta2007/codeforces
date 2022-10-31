#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SITO_MAX = 100000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

int n, k;
map<vector<pair<int, int>>, int> cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	ll sol = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		auto v = factor_small(x);
		for (auto& [p, a] : v) {
			a %= k;
		}

		int j = 0;
		for (int i=0; i<(int)v.size(); i++) {
			if (v[i].second != 0) {
				v[j++] = v[i];
			}
		}
		v.resize(j);


		auto w = v;
		for (auto& [p, a] : w) {
			a = k - a;
		}
		
		sol += cnt[w];
		cnt[v]++;
	}
	cout << sol << "\n";
}