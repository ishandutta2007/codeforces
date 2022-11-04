#include<bits/stdc++.h>
using namespace std;

int main() {
	int T, n, m;
	for (cin >> T; T --;) {
		cin >> n >> m;
		int s = 0;
		for (int i = 1; i <= n; i ++) {
			int a;
			cin >> a;
			s += a;
		}
		if (s == m) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}