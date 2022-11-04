#include <bits/stdc++.h>

using namespace std;

const int MX = 500005;

int Tc, N, M, i, j;

int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (cin >> Tc; Tc--; ) {
		cin >> N >> M >> i >> j;
		cout << "1 1 " << N << ' ' << M << '\n';
	}

	return 0;

}