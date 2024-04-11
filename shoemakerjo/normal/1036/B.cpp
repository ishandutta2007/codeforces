#include <bits/stdc++.h>

using namespace std;
#define ll long long
int q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// int q;
	cin >> q;
	ll n, m, k;
	while (q--) {
		cin >> n >> m >> k;
		if (n < m) swap(n, m);
		if (n % 2 != m % 2) {
			k-=1LL;
			n-=1LL;
		}
		else if (n % 2 != k % 2) {
			n-=1LL;
			m-=1LL;
			k-=2LL;
		}
		if (k < n) cout << -1 << endl;
		else cout << k << endl;

	}
}