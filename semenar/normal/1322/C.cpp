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
#include <chrono>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl '\n'

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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	if (a < b) return gcd(b, a);
	return gcd(b, a % b);
}

const int N = 10000001;

int num_cnt[N];
int pref_cnt[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	mt19937_64 rang(chrono::steady_clock::now().time_since_epoch().count());

	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n, m;
		cin >> n >> m;

		vector<ll> ran(n);
		for (int i = 0; i < n; i++) ran[i] = rang();

		vector<ll> num(n);
		for (int i = 0; i < n; i++) cin >> num[i];

		vector<pair<ll, int>> hs_who(n);
		for (int i = 0; i < n; i++) hs_who[i].second = i;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			hs_who[b].first ^= ran[a];
		}

		sort(all(hs_who));

		ll great_nod = 0;
		ll running_sum = 0;
		ll last_hs = -1;

		for (auto el : hs_who) {
			if (last_hs != el.first) {
				if (last_hs != 0) great_nod = gcd(great_nod, running_sum);
				running_sum = 0;
				last_hs = el.first;
			}
			running_sum += num[el.second];
		}

		if (last_hs != 0) great_nod = gcd(great_nod, running_sum);

		cout << great_nod << endl;
	} 

	return 0;
}