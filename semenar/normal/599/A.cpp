#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>

#define max(a, b) (a > b ? a : b)

using namespace std;

string to_str(int val) {
	if (val < 0) return "-" + to_str(-val);
	if (val < 10) return string(1, '0' + val);
	return to_str(val / 10) + to_str(val % 10);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	if (d3 > d1 + d2) d3 = d1 + d2;
	if (d1 > d2 + d3) d1 = d2 + d3;
	if (d2 > d1 + d3) d2 = d1 + d3;
	cout << d1 + d2 + d3 << endl;
	return 0;
}