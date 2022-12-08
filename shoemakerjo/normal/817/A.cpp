#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x, y;
	cin >> x >> y;
	if (abs(x1-x2) % x != 0 || abs(y1-y2)%y != 0) {
		cout << "NO" << endl;
	}
	else {
		if (abs(x1-x2)/x % 2 == abs(y1-y2)/y % 2) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	// cin >> x1;
}