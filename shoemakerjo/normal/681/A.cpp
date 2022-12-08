#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string cur;
	int before, after;
	bool good = false;
	for (int i = 0; i < n; i++) {
		cin >> cur >> before >> after;
		if (before >= 2400 && after > before) good = true;
	}
	if (good) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin >> n;
}