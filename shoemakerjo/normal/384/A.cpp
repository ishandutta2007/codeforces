#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = (n*n+1)/2;
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i%2 == 0) {
				if (j%2 == 0) cout << 'C';
				else cout << '.';
			}
			else {
				if (j%2 == 1) {
					cout << 'C';
				}
				else cout << '.';
			}
		}
		cout << endl;
	}
	// cin >> n;
}