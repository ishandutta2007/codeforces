#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define max(a, b) (a > b ? a : b)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> bus(n);
	bool seated = false;
	for (int i = 0; i < n; i++) {
		cin >> bus[i];
		if (!seated) {
			if (bus[i][0] == 'O' && bus[i][1] == 'O') {
				seated = true;
				bus[i][0] = '+';
				bus[i][1] = '+';
			}
		}
		if (!seated) {
			if (bus[i][3] == 'O' && bus[i][4] == 'O') {
				seated = true;
				bus[i][3] = '+';
				bus[i][4] = '+';
			}
		}
	}
	if (!seated) {
		cout << "NO";
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << bus[i] << endl;
		}
	}
	return 0;
}