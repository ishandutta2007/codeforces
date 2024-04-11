#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[109];
int main() {
	cin >> n >> m >> k; m--;
	int ret = 999999999;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] > 0 && a[i] <= k) ret = min(ret, abs(i - m) * 10);
	}
	cout << ret << endl;
	return 0;
}