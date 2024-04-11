#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


bool ok(long long x) {
	for (char c : to_string(x)) {
		if (c != '0' && x % (c - '0') != 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		while (!ok(n)) {
			++n;
		}
		cout << n << "\n";
	}
	return 0;
}