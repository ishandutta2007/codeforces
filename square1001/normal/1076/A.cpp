#include <string>
#include <iostream>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	string opt = s.substr(0, n - 1);
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] > s[i + 1]) {
			opt = s.substr(0, i) + s.substr(i + 1);
			break;
		}
	}
	cout << opt << '\n';
	return 0;
}