#include <iostream>

using namespace std;

int main() {
	int len;
	cin >> len;
	char line[len];
	cin >> line;
	int a = 0;
	int b= 0;
	for (int i = 0; i < len; ++i) {
		if (line[i] == 'A') {
			a++;
		}
		else b++;
	}
	if (a > b) {
		cout << "Anton" << endl;
	}
	else if (b > a) {
		cout << "Danik" << endl;
	}
	else cout << "Friendship" << endl;
}