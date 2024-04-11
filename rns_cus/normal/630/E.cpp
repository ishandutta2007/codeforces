#include <bits/stdc++.h>
using namespace std;

long long stx, sty, enx, eny, n, m;

int main() {
//	freopen("e.in", "r", stdin);
	cin >> stx >> sty >> enx >> eny;
	n = enx - stx;
	m = (eny - sty) / 2 + 1;
	cout << (n / 2 + 1) * m + n / 2 * (m - 1) << endl;
	return 0;
}