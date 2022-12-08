#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a + c) & 1) << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}