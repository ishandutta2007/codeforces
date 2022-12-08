#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	if  (l == 1 && r == n) {
		cout << 0 << endl;
		cin >> n;
		return 0;
	}
	if (l == 1) {
		cout << abs(r-pos)+1 << endl;
		cin >> n;
		return 0;
		// cin >> n;
	}
	if (r == n) {
		cout << abs(pos-l)+1 << endl;
		cin >> n;
		return 0;
	}
	int o1 = 0;
	int o2 = 0;
	o1 = abs(pos-l)+1 + r-l+1;
	o2 = abs(r-pos)+1 + r-l+1;
	cout << min(o1, o2) << endl;
	cin >> n; 
}