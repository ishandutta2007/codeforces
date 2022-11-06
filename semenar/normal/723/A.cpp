#include <iostream>
#include <string>

#define max(a, b) (a > b ? a : b)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;
	cout << abs(x1 - x2) + abs(x2 - x3) + abs(x3 - x1) - max(abs(x1 - x2), max(abs(x2 - x3), abs(x3 - x1)));
	return 0;
}