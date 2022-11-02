#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, m, c[109]; string s;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s, c[s.size()]++;
	cin >> s;
	int l = 0, r = 0;
	for (int i = 1; i <= s.size(); i++) {
		r += c[i];
		if (i != s.size()) l += c[i];
	}
	r--;
	cout << l + l / m * 5 + 1 << ' ' << r + r / m * 5 + 1 << endl;
	return 0;
}