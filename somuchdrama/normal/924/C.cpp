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

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(20);

	int n; cin >> n;
	vector <int> m(n);
	for (auto & i : m) cin >> i;


	set <int> ok;
	set <int> nok;

	for (int i = 0; i < n; ++i) {
		nok.insert(-i);
		while (ok.size() < m[i] + 1) {
			ok.insert(-(*nok.begin()));
			nok.erase(nok.begin());
		}
	}

	long long ans = 0;
	int am = 0; 
	for (int i = 0; i < n; ++i) {
		if (ok.count(i)) {
			am++; ok.erase(i);
		}
		ans += max(0, (am - m[i] - 1));
	}
	cout << ans << '\n';
}