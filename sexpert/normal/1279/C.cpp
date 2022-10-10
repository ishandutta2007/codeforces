#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> pos(n + 1);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	}
	ll ans = 0, ri = -1;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int p = pos[x];
		if(p <= ri)
			ans++;
		else {
			ans += 2*(p - i) + 1;
			ri = p;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}