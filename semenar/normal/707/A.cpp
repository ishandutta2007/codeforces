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

	int n, m;
	cin >> n >> m;
	bool colored = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char color;
			cin >> color;
			if (color != 'W' && color != 'B' && color != 'G') colored = true;
		}
	}
	if (colored) cout << "#Color";
	else cout << "#Black&White";
	return 0;
}