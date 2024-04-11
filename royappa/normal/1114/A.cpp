#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{

	LL g, p, b;
	LL x, y, z;
	cin >> x >> y >> z;
	cin >> g >> p >> b;
	if (x > g) {
		cout << "NO" << endl;
		exit(0);
	}
	g -= x;
	if (y > g+p) {
		cout << "NO" << endl;
		exit(0);
	}
	/*
	g -= min(y, g);
	y -= min(y, g);
	p -= min(y, p);
	y -= min(y, p);
	*/
	bool can = false;
	for (int i = 0; i <= g; i++) {
		if (g-i <= y && p >= y-i) {
			g -= i;
			p -= y-i;
			can = true;
			break;
		}
	}
	if (!can) cout << "NO" << endl;
	if (z > g+p+b) {
		cout << "NO" << endl;
		exit(0);
	}
	cout << "YES" << endl;
	exit(0);
}