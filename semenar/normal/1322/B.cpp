#pragma comment(linker, "/STACK:256000000")
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
#include <ctime>
#include <random>
#include <map>
#include <bitset>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

#define X first
#define Y second

using namespace std;

mt19937 rng(time(NULL));

using ll = long long;
using vi = vector<int>;
using graph = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
using vb = vector<bool>;

const ll MOD = 998244353;
const int INF = 1000000007;

struct dsu {
	vector<int> lnk;
	vector<int> rnk;

	dsu(int n) {
		lnk.resize(n);
		rnk.resize(n);
		for (int i = 0; i < n; i++) lnk[i] = i, rnk[i] = 1;
	}

	int get_parent(int v) {
		if (v == lnk[v]) return v;
		else return lnk[v] = get_parent(lnk[v]);
	}

	bool same(int u, int v) {
		return get_parent(u) == get_parent(v);
	}

	void merge(int u, int v) {
		u = get_parent(u);
		v = get_parent(v);
		if (u == v) return;
		if (rnk[u] < rnk[v]) {
			lnk[u] = v;
			rnk[v] += rnk[u];
		}
		else {
			lnk[v] = u;
			rnk[u] += rnk[v];
		}
	}
};

const int N = 10000001;

int num_cnt[N];
int pref_cnt[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 0;

	for (int bit = 0; bit <= 24; bit++) {
		int lim = min(N, (1 << (bit + 1)));
		for (int i = 0; i < lim; i++) {
			num_cnt[i] = 0;
			pref_cnt[i] = 0;
		}
		for (auto el : a) {
			num_cnt[el & ((1 << (bit + 1)) - 1)]++;
		}
		pref_cnt[0] = num_cnt[0];
		for (int i = 1; i < lim; i++) pref_cnt[i] = pref_cnt[i - 1] + num_cnt[i];

		int ones = 0;
		for (int i = 0; i < lim; i++) {
			// [(1 << bit) - i, (1 << (bit + 1) - i))
			if ((1 << bit) - i > 0 && (1 << bit) - i <= lim) ones -= num_cnt[i] * pref_cnt[(1 << bit) - i - 1];
			else if ((1 << bit) - i > lim) ones -= num_cnt[i] * n;
			else {
				if ((1 << bit) + (1 << (bit + 1)) - i <= lim) ones += num_cnt[i] * (n - pref_cnt[(1 << bit) + (1 << (bit + 1)) - i - 1]);
			}

			if ((1 << (bit + 1)) - i <= lim) ones += num_cnt[i] * pref_cnt[(1 << (bit + 1)) - i - 1];
			else ones += num_cnt[i] * n;
		}

		for (auto el : a) {
			if ((el + el) & (1 << bit)) ones--;
		}

		ones /= 2;
		if (ones % 2) ans ^= (1 << bit);
	}

	cout << ans << endl;

	return 0;
}