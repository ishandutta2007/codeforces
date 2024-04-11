#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


int main()
{
	int t, n, k1, k2;
	cin >> t;
	while (t--) {
		cin >> n >> k1 >> k2;
		bool can = false;
		for (int i = 0; i < k1; i++) {
			int x;
			cin >> x;
			if (x == n) can = true;
		}
		while (k2--) {
			int x;
			cin >> x;
		}
		cout << (can ? "YES" : "NO") << endl;
	}
	exit(0);
}