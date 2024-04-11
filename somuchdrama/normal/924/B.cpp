#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int n, u;
vector <int> e;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(20);

	cin >> n >> u;
	e.resize(n);
	for (auto & i : e) cin >> i;

	long double ans = -1;
	
	for (int i = 0; i < n; ++i) {
		int k = distance(e.begin(), upper_bound(e.begin(), e.end(), u + e[i])) - 1;
		if (i + 2 > k) continue;

		ans = max(ans, ((long double)(e[k] - e[i + 1])) / (e[k] - e[i]));
	}
	cout << ans << '\n';
}