#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[24], val[9616];
int main() {
	for (int i = 0; i < 9600; i++) {
		int yr = i / 12, mt = i % 12;
		if (mt == 3 || mt == 5 || mt == 8 || mt == 10) val[i] = 30;
		else if (mt != 1) val[i] = 31;
		else {
			if (yr % 400 == 0) val[i] = 29;
			else if (yr % 100 == 0) val[i] = 28;
			else if (yr % 4 == 0) val[i] = 29;
			else val[i] = 28;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	bool res = false;
	for (int i = 0; i < 9000; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (a[j] != val[i + j]) flag = false;
		}
		if (flag) res = true;
	}
	cout << (res ? "YES" : "NO") << endl;
	return 0;
}