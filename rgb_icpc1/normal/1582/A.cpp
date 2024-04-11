#include <bits/stdc++.h>

using namespace std;

const int MX = 100005;

int Tc, N;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b, c;
	for (cin >> Tc; Tc--; ) {
		cin >> a >> b >> c;
		cout << (a + c) % 2 << endl;
	}

	return 0;

}