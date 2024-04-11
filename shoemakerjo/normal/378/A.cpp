#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int aw = 0, bw = 0, d = 0;
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= 6; i++) {
		if (abs(a-i) < abs(b-i)) aw++;
		else if (abs(b-i) < abs(a-i)) bw++;
		else d++;
	}
	cout << aw << " " << d << " " << bw << endl;
	// cin >> a;
}