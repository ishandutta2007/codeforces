#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool good[n];
	for (int i = 0; i < n; i++) good[i] = true;
		int cur;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cur;
			if (cur == 1) good[i] = false;
			if (cur == 2) good[j] = false;
			if (cur == 3) {
				good[i] = false;
				good[j] = false;
			}
		}
	}
	bool start = false;
	int ct = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) ct++;
	}
	cout << ct << endl;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			if (start) {
				cout << " ";
			}
			start = true;
			cout << i+1;
			
		}
	}
	if (ct > 0) cout << endl;
	// cin >> n;
}