#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>


using namespace std;


int32_t main() {
	bool lckd = false;
	string clr = "blue";
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "lock") {
			lckd = true;
		}
		else if (s == "unlock") {
			lckd = false;
		}
		else if (!lckd) {
			clr = s;
		}
	}
	cout << clr << "\n";
	return 0;
}