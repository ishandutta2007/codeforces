#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		long long A, B, C, D;
		cin >> A >> B >> C >> D;
		if (B >= A) {
			cout << B << endl;
		}
		else {
			if (C <= D) {
				cout << -1 << endl;
			}
			else {
				long long rem = A - B;
				long long rept = (rem + (C - D) - 1) / (C - D);
				cout << B + rept * C << endl;
			}
		}
	}
	return 0;
}