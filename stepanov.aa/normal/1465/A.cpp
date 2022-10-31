#include <iostream>
#include <string>


using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int i = n - 1;
		while (i >= 0 && s[i] == ')') {
			--i;
		}
		if ((n - i - 1) > i + 1) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	return 0;
}