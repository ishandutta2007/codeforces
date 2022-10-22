#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int x, y, z;
	cin >> x >> y >> z;
	int tp = 0;
	if (x + z > y) {
		tp += 1;
	}
	if (y + z > x) {
		tp += 2;
	} 
	if ((x + z + y) % 2 == 0 && x + z >= y && y + z >= x) {
		tp += 4;
	}
	//cout << tp << "\n";
	if (tp == 1) {
		cout << "+";
	} else if (tp == 2) {
		cout << "-";
	} else if (tp == 4) {
		cout << "0";
	} else {
		cout << "?";
	}
	cout << "\n";
}