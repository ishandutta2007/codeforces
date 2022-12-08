#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	int c256, c32;
	c256 = min(k2, min(k5, k6));
	k2-=c256;
	c32 = min(k3, k2);
	cout << 256*c256+32*c32 << endl;
	// cin >> k2;
}