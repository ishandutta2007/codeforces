#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num - 1);
	}
	vector<int> cost;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cost.push_back(num);
	}

	vector<vector<int>> here(k);
	for (int i = 0; i < n; ++i) {
		here[arr[i]].push_back(cost[i]);
	}

	vector<int> all;
	int cnt = k;
	for (int i = 0; i < k; ++i) {
		sort(here[i].begin(), here[i].end());
		if (szof(here[i])) {
			--cnt;
			here[i].pop_back();
			for (int num : here[i]) {
				all.push_back(num);
			}
		}
	}

	sort(all.begin(), all.end());
	ll ans = 0;
	for (int i = 0; i < cnt; ++i) {
		ans += all[i];
	}

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}