#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

typedef int_fast64_t ll;
typedef long double ld;

#define int int_fast64_t
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define input(a) for (auto& _ : a) cin >> _
#define print(a) for (auto _ : a) cout << _

//#define x first
//define y second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	input(a);
	sort(rall(a));
	cout << a[0] + a[1] << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}