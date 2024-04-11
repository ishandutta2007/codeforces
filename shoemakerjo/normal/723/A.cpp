#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int mind = 1000000;
	int x1;
	int x2;
	int x3;
	cin >> x1 >> x2 >> x3;
	for (int i = 0; i <= 100; ++i) {
		int curd = abs(x1-i) + abs(x2-i) + abs(x3-i);
		if (curd < mind) {
			mind = curd;
		}
	}
	cout << mind << endl;
}