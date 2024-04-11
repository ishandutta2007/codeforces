#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, x, a[3];
int main() {
	cin >> n >> x;
	for (int i = 0; i < 3; i++) a[i] = i;
	for (int i = 0; i < n % 6; i++) {
		if (i & 1) swap(a[1], a[2]);
		else swap(a[0], a[1]);
	}
	cout << a[x] << endl;
	return 0;
}