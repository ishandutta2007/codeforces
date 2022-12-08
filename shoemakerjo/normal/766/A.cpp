#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << -1 << endl;
	}
	else {
		cout << max(a.length(), b.length()) << endl;
	}

}