#include <bits/stdc++.h>

using namespace std;

const int MX = 200005;
const int INF = 1000000007;

int Tc, N, H[MX];

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
		for (i = 0; i < N; i++) cin >> H[i];
		sort(H, H + N);
		int mn = INF, pos;
		for (i = 1; i < N; i++) {
			if (H[i] - H[i - 1] < mn) mn = H[i] - H[i - 1], pos = i;
		}
		if (pos == 1 && N == 2) pos = 0;
		for (i = pos; i < N; i++) cout << H[i] << ' ';
		for (i = 0; i < pos; i++) cout << H[i] << ' '; cout << '\n';
	}

	return 0;

}