#include <bits/stdc++.h>
using namespace std;
int n, a, s, m, l, r;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a, s += a;
	cin >> m;
	bool flag = false;
	for(int i = 0; i < m; i++) {
		cin >> l >> r;
		if(s <= r) {
			cout << max(l, s) << endl;
			flag = true; break;
		}
	}
	if(!flag) cout << -1 << endl;
	return 0;
}