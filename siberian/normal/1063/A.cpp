#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()
	
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	sort(all(s));
	cout << s;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	int t;
	//cin >> t;
	t = 1;
	while (t--)
		solve();
	return 0;
}