#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long long x1, x2, a, b;
	cin >> x1 >> x2 >> a >> b;
	long long d = x2 - x1;
	bool inverted = false;
	if (d < 0) {
		d = -d;
		a = -a;
		b = -b;
		swap(a, b);
		inverted = true;
	}

	if (a <= d && d <= b) {
		cout << "FIRST" << endl;
		cout << x2 << endl;
		return 0;
	}
	

	if (a <= 0 && b <= 0) {
		cout << "DRAW" << endl;
		return 0;
	}
	if (b >= 0 && a <= 0 && abs(b) <= abs(a)) {
		if (d <= b) {
			cout << "FIRST" << endl;
			cout << x2 << endl;
			return 0;
		} else {
			cout << "DRAW" << endl;
			return 0;
		}
	}
	if (a >= 0 && b >= 0) {
		if (a >= 1) {
			d %= (a + b);
			if (d == 0) {
				d = a + b;
			}
			if (d >= 1 && d <= a - 1) {
				cout << "DRAW" << endl;
				return 0;
			}
			if (d >= a && d <= b) {
				cout << "FIRST" << endl;
				cout << x1 + ((!inverted) ? d : -d) << endl;
				return 0;
			}
			if (d >= b + 1 && d <= a + b - 1) {
				cout << "DRAW" << endl;
				return 0;
			}
			cout << "SECOND" << endl;
			return 0;
		} else {
			if (d <= b) {
				cout << "FIRST" << endl;
				cout << x2 << endl;
				return 0;
			}
			cout << "DRAW" << endl;
			return 0;
		}
	}

	if (d <= b) {
		cout << "FIRST" << endl;
		cout << x2 << endl;
		return 0;
	}
	cout << "DRAW" << endl;

	return 0;
}