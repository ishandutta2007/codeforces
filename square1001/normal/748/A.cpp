#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, k;
int main() {
	cin >> n >> m >> k; k--;
	cout << k / (2 * m) + 1 << ' ' << k % (2 * m) / 2 + 1 << ' ' << (k % 2 ? 'R' : 'L') << endl;
	return 0;
}