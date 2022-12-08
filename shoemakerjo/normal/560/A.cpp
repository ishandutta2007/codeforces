#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool hasO = false;
	int cur;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if (cur==1) hasO = true;
	}
	if (hasO) cout << -1 << endl;
	else cout << 1 << endl;

}