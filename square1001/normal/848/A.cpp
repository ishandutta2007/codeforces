#include <string>
#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	string ret;
	for (int i = 0; n >= 1; i++) {
		for (int j = 2; ; j++) {
			if (j * (j - 1) / 2 > n) {
				ret += string(j - 1, i + 97);
				n -= (j - 1) * (j - 2) / 2;
				break;
			}
		}
	}
	cout << (ret.size() == 0 ? "a" : ret) << endl;
	return 0;
}