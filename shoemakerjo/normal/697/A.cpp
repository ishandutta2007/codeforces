#include <iostream>

using namespace std;

int main() {
	int t, s, x;
	cin  >> t >> s >> x;
	int diff = x - t;
	if (diff < 0) {
		cout << "NO" << endl;
	}
	else {
		if (diff == 0) cout <<"YES" << endl;
		else if (diff == 1) cout << "NO" << endl;
		else if (diff % s == 0 || diff % s == 1) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	cin >> t;
}