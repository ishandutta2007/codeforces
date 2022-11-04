#include <bits/stdc++.h>

using namespace std;

const int MX = 500005;

int Tc, N;

int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> N;
		int cnt = 0;
		while (!(N & 1)) {
			N >>= 1;
			cnt++;
		}
		if (!cnt) cout << "Bob\n";
		else if (N > 1) cout << "Alice\n";
		else if (cnt & 1) cout << "Bob\n";
		else cout << "Alice\n";
	}

	return 0;

}