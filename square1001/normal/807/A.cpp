#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a[1009], b[1009];
int main() {
	cin >> n;
	bool f = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] != b[i]) f = true;
	}
	if (f) cout << "rated" << endl;
	else {
		bool f1 = false;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] < a[i]) f1 = true;
		}
		cout << (f1 ? "unrated" : "maybe") << endl;
	}
	return 0;
}