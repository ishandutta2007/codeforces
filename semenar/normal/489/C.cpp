#include <iostream>
#include <algorithm>
#include <string>

#define SP << " " <<

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	if (s < 1 || s > 9 * n) {
		if (s == 0 && n == 1) {
			cout << "0 0";
		}
		else {
			cout << "-1 -1";
		}
	}
	else {
		string a = "";
		int tmp = s;
		a += (char)(max(1, tmp - 9 * (n - 1)) + '0');
		tmp -= max(1, tmp - 9 * (n - 1));
		for (int i = 1; i < n; i++) {
			a += (char)(max(0, tmp - 9 * (n - i - 1)) + '0');
			tmp -= max(0, tmp - 9 * (n - i - 1));
		}
		cout << a << " ";
		a = "";
		tmp = s;
		for (int i = 0; i < n; i++) {
			a += (char)(min(9, tmp) + '0');
			tmp -= min(9, tmp);
		}
		cout << a;
	}
	return 0;
}