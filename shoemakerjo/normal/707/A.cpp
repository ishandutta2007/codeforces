#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool bw = true;
	char c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> c;
			if (c == 'C' || c== 'M' || c =='Y') {
				bw = false;
			}
		}
	}
	if (bw) {
		cout << "#Black&White" << endl;

	}
	else cout << "#Color" << endl;
}