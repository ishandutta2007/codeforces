#include <bits/stdc++.h>

using namespace std;

int x, y, z;
int a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> z >> a >> b >> c;

	a-= x;
	if (a < 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (a + b < y) {
		cout << "NO" << endl;
		return 0;
	}
	if (a + b + c < y + z) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
}