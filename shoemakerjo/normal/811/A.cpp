#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ct = 1;
	while (1) {
		if (ct%2 == 1) {
			if (a < ct) {
				cout << "Vladik" << endl;
				break;
			}
			a -= ct;
		}
		else {
			if (b < ct) {
				cout << "Valera" << endl;
				break;
			}
			b-=ct;
		}
		ct++;
	}
	cin >> a;
}