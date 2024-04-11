#include <bits/stdc++.h>
using namespace std;
int xa, ya, xb, yb, x, y;
int main() {
	cin >> xa >> ya >> xb >> yb >> x >> y;
	int dx = abs(xb - xa), dy = abs(yb - ya);
	if(dx % x != 0 || dy % y != 0) cout << "NO" << endl;
	else if((dx / x) % 2 != (dy / y) % 2) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}