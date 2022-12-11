#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = (int)1e9 + 41;

void go(int v, int pr, const vector<vector<pair<int, int>>> &es, vector<ll> &d0, vector<ll> &d1, int k) {
	ll score = 0;
	vector<ll> change;
	for (const auto &[w, we] : es[v]) {
		if (w == pr) continue;
		go(w, v, es, d0, d1, k);
		score += d0[w];
		change.push_back(d1[w] + we - d0[w]);
	}
	d0[v] = d1[v] = score;
	sort(change.rbegin(), change.rend());
	for (int i = 0; i < (int)change.size(); i++) {
		if (i < k) d0[v] += max(0ll, change[i]);
		if (i < k - 1) d1[v] += max(0ll, change[i]);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<pair<int, int>>> es(n);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		v1--;
		v2--;
		es[v1].emplace_back(v2, c);
		es[v2].emplace_back(v1, c);
	}

	vector<ll> d0(n, -1), d1(n, -1);
	go(0, -1, es, d0, d1, k);
	cout << d0[0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}