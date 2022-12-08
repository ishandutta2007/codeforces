#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(int x) {
	if (x == 0) {
		cout << 1 << " " << 1 << endl;
		return;
	}
	for (int m = 1; m <= 100000; m++) {
		ll cur = 1LL*m*m;
		ll need = cur-x;
		if (cur <= x) continue;
		ll tempo = sqrt(need);
		if (tempo*tempo == need) {
			ll div = (m+0LL)/tempo;
			if ((m+0LL)/div == tempo) {
				cout << m << " " << div << endl;
				return;
			}
		}
	}
	cout << -1 << endl;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int x;
	while (t--) {
		cin >> x;
		solve(x);
	}
	cin >> t;
}