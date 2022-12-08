#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string str;
	cin >> str;

	int fAB = str.find("AB");
	int lAB = str.rfind("AB");

	int fBA = str.find("BA");
	int lBA = str.rfind("BA");

	if (fAB >= 0 && fBA >= 0 && (abs(fAB-lBA) > 1 || abs(fBA-lAB) > 1)) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	// cin >> str;
}