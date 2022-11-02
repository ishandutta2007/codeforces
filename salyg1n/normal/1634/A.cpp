#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>

typedef long long ll;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define input(a) for(auto& _ : a) cin >> _
#define print(a) for (auto _ : a) cout << _
#define x first
#define y second
#define umap unordered_map

//#define int long long

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string s1 = s;
	reverse(all(s1));
	if (s1 == s || k == 0)
		cout << 1 << "\n";
	else
		cout << 2 << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}