#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if ((b * d * f > a * c * e && b * d * f != 0) || (c == 0 && d > 0) || (a == 0 && b * d > 0)) {
		cout << "Ron" << endl;
	} else {
		cout << "Hermione" << endl;
	}

	return 0;
}