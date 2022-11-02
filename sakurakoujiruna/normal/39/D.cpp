#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int x1, y1, z1; cin >> x1 >> y1 >> z1;
	int x2, y2, z2; cin >> x2 >> y2 >> z2;
	bool f = (x1 == x2) | (y1 == y2) | (z1 == z2);
	cout << (f ? "YES" : "NO") << '\n';
	return 0;
}