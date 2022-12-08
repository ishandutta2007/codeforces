#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool horiz[n];
	bool vert[n];
	bool ans[n*n];

	for (int i = 0; i < n; i++) {
		horiz[i] = false;
		vert[i] = false;
	}
	int hc;
	int vc;
	for (int i = 0; i < n*n; i++) {
		cin >> hc >> vc;
		ans[i] = false;
		if (!horiz[hc-1] && !vert[vc-1]) {
			ans[i] = true;
			horiz[hc-1] = true;
			vert[vc-1] = true;

		}
	}
	bool started = false;
	for (int i = 0; i < n*n; i++) {
		if (ans[i]) {
			if (started) {
				cout << " ";
			}
			else started = true;
			cout << i+1;
		}
	}
	cout << endl;
	// cin >> n;
}