#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
const double pi = acos(-1);
int h, m, s, t1, t2;
int main() {
	cin >> h >> m >> s >> t1 >> t2;
	h %= 12;
	t1 %= 12;
	t2 %= 12;
	int a1 = 3600 * h + 60 * m + s;
	int a2 = 720 * m + 12 * s;
	int a3 = 720 * s;
	int a4 = 3600 * t1;
	int a5 = 3600 * t2;
	int b[3] = { a1, a2, a3 };
	sort(b, b + 3);
	b[1] -= b[0];
	b[2] -= b[0];
	a4 -= b[0];
	a5 -= b[0];
	if (a4 < 0) a4 += 43200;
	if (a5 < 0) a5 += 43200;
	if (a4 > a5) swap(a4, a5);
	cout << (a5 < b[1] || b[1] < a4 && a5 < b[2] || b[2] < a4 ? "YES" : "NO") << endl;
	return 0;
}