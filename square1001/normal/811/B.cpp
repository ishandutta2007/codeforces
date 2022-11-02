#include <bits/stdc++.h>
using namespace std;
int n, q, l, r, x, p[10009], t[10009], inv[10009];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> p[i], p[i]--;
	for(int i = 0; i < q; i++) {
		cin >> l >> r >> x; l--; x--;
		fill(inv, inv + n, -1);
		for(int j = l; j < r; j++) inv[p[j]] = j;
		int cnt = 0;
		for(int j = 0; j < n; j++) {
			if(inv[j] != -1) t[cnt++] = j;
		}
		cout << (t[x - l] == p[x] ? "Yes" : "No") << endl;
	}
	return 0;
}