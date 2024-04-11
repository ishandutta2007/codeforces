#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <map>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

void comp_dfs(vector<vi> &gr, int v, vector<int> &comp, int col) {
	if (comp[v] != -1) return;
	comp[v] = col;
	for (auto w : gr[v]) comp_dfs(gr, w, comp, col);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, q;
	cin >> n >> q;
	vi num(n);
	for (int i = 0; i < n; i++) cin >> num[i];

	vector<pii> sort_num;
	for (int i = 0; i < n; i++) sort_num.eb(num[i], i);
	sort(all(sort_num));

	vector<int> prefsum(n);
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || sort_num[i].first != sort_num[i + 1].first) prefsum[sort_num[i].second] -= 1;
		if (i == 0 || sort_num[i].first != sort_num[i - 1].first) prefsum[sort_num[i].second] += 1;
	}

	for (int i = 1; i < n; i++) prefsum[i] += prefsum[i - 1];

	vector<int> bnd(1);
	for (int i = 0; i < n; i++) if (prefsum[i] == 0) bnd.pb(i + 1);

	int ans = 0;
	for (int sgt = 1; sgt < sz(bnd); sgt++) {
		int l = bnd[sgt - 1], r = bnd[sgt];
		map<int, int> cnt;
		for (int i = l; i < r; i++) cnt[num[i]]++;
		int mx = 0;
		for (auto el : cnt) {
			if (el.second > mx) mx = el.second;
		}
		ans += (r - l) - mx;
	}

	cout << ans << endl;

	return 0;
}