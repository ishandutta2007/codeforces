#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	int num = y-1;
	if (y == 0) {
		cout << "No" << endl;
	}
	else if (y == 1) {
		if (x == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else if (x == 0) {
		if (y ==1 ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else if (num <= x && (x-num) % 2 == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cin >> x;
}