#include <iostream>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	for (int i = 1; ; i++) {
		if (i % 2 == 1) {
			if (a >= i) a -= i;
			else {
				cout << "Vladik" << endl;
				break;
			}
		}
		else {
			if (b >= i) b -= i;
			else {
				cout << "Valera" << endl;
				break;
			}
		}
	}
	return 0;
}