#include <bits/stdc++.h>
using namespace std;

long long x, y, z, s, ss, a, b, c;

int main() {
//	freopen("a.in", "r", stdin);
	cin >> x >> y >> z;
    s = x * y * z;
	ss = sqrt(s);
	if (ss * ss < s) ss ++;
	a = ss / x, b = ss / y, c = ss / z;
	cout << (a + b + c) * 4 << endl;
	return 0;
}