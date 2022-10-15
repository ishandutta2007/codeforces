#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define int long long

using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector <int> v(n), t(n);
	for (auto & i : v) cin >> i;
	for (auto & i : t) cin >> i;

	int bal = 0;
	multiset <int> who;
	for (int i = 0; i < n; ++i) {
		who.insert(v[i] + bal);
		int ans = 0;
		while (who.size() > 0 && *(who.begin()) - bal - t[i] <= 0) {
			ans += *(who.begin()) - bal;
			who.erase(who.begin());
		}
		bal += t[i];
		ans += t[i] * ((int)who.size());
		cout << ans << ' ';
	}
	cout << '\n';
}