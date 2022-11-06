#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>

#define max(a, b) (a > b ? a : b)

using namespace std;

string to_str(int val) {
	if (val < 0) return "-" + to_str(-val);
	if (val < 10) return string(1, '0' + val);
	return to_str(val / 10) + to_str(val % 10);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	map<string, int> hints;
	for (int i = 0; i < n; i++) {
		string login;
		cin >> login;
		if (hints[login] == 0) {
			cout << "OK" << endl;
		}
		else {
			cout << login + to_str(hints[login]) << endl;
		}
		hints[login]++;
	}
	return 0;
}