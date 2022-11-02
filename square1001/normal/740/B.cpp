#include <bits/stdc++.h>
using namespace std;
int n, m, a[109], l, r, sum;
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) {
		cin >> l >> r;
		int s = 0;
		for(int j = l - 1; j < r; j++) s += a[j];
		if(s > 0) sum += s;
	}
	cout << sum << endl;
	return 0;
}