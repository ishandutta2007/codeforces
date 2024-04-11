#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

using namespace std;
vector <int> pr, lp;


void calc_primes(int n) { 
	lp.assign(n + 1, 0); 
    pr.clear();
	for (int i = 2; i <= n; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];
	}
} 

int get_best(int x) {
	while (lp[x] != x)
		x /= lp[x];
	return x;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x2;
	cin >> x2;
	calc_primes(x2);

	int ans = x2;
	for (int x1 = x2 - get_best(x2) + 1; x1 <= x2; ++x1) {
		if (get_best(x1) == x1) continue;
		ans = min(ans, max(3, x1 - get_best(x1) + 1));
	}
	cout << ans << '\n';
}