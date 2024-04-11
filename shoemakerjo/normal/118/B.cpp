#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int maxl = 2*n+1;
	for (int i = 0; i <= n; i++) {
		int len = 2*i+1;
		int pre = (maxl-len)/2;
		for (int j = 0; j < pre; j++) {
			cout << "  ";
		}
		for (int j = 0; j <= i; j++) {
			cout << j;
			if (i > 0) cout << " ";
		}
		for (int j = i-1; j >= 0; j--) {
			cout << j;
			if (j > 0) cout << " ";
		}
		cout << endl;
	}
	for (int i = n-1; i >= 0; i--) {
		int len = 2*i+1;
		int pre = (maxl-len)/2;
		for (int j = 0; j < pre; j++) {
			cout << "  ";
		}
		for (int j = 0; j <= i; j++) {
			cout << j;
			if (i > 0) cout << " ";
		}
		for (int j = i-1; j >= 0; j--) {
			cout << j;
			if (j > 0) cout << " ";
		}
		cout << endl;
	}
	// cin >> n;
}