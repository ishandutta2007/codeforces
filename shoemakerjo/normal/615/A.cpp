#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	bool on[m+1];
	for (int i = 1; i <= m; i++) {
		on[i] = false;
	}
	
	string cur;
	int temp;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> y;
			on[y] = true;
		}
	}
	bool ok = true;
	for (int i = 1; i <= m; i++) {
		if (!on[i]) ok = false;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin >> n;
}