#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for(auto &x : v)
		cin >> x;
	int tot = 0, ma = -1, mp = -1;
	for(int i = 0; i < n; i++) {
		if(v[i] > ma) {
			ma = v[i];
			mp = i;
		}
		if(tot + v[i] > s) {
			cout << mp + 1 << '\n';
			return;
		}
		tot += v[i];
		if(i == n - 1) {
			cout << "0\n";
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}