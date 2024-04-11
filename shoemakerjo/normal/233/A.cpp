#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n% 2 == 1) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < n; i+=2) {
			if (i > 0) cout << " ";
			cout << i+2 << " " << i+1;
		}
		cout << endl;
	}
	cin >> n;
}