#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	string s;
	cin >> q;
	int L, R, U, D;
	for (int i = 0; i < q; ++i) {
		L = R = U = D = 0;
		cin >> s;
		for (char c: s) {
			if (c == 'L') ++L;
			else if (c == 'R') ++R;
			else if (c == 'U') ++U;
			else ++D;
		}
		L = R = min(L, R);
		U = D = min(U, D);
		if (U == 0 && L > 1) L = R = 1;
		else if (L == 0 && U > 1) U = D = 1;
		cout << L + R + U + D << '\n';
		for (int i = 0; i < L; ++i) cout << 'L';
		for (int i = 0; i < U; ++i) cout << 'U';
		for (int i = 0; i < R; ++i) cout << 'R';
		for (int i = 0; i < D; ++i) cout << 'D';
		cout << '\n';
	}
	return 0;
}