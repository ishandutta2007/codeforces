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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;

	cin >> n;

	int ans = 0;
	int balance = 0;

	int open = 0;
	int closed = 0;

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '(') {
			open++;
			balance++;
			if (balance == 0) ans++;
		}
		else {
			open--;
			balance--;
		}
		if (balance < 0) ans++;
	}

	if (open != closed) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}