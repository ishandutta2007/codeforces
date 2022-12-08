#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> vals;
int n;
ll m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		vals.push_back(cur);
	}
	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());

	ll o1 = m/(k+1);
	ll o2 = m - o1;

	ll ans = o1 * vals[1] + o2 * vals[0];

	cout << ans << endl;
}