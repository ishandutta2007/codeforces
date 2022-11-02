#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
string s;
int main() {
	cin >> s;
	int a = 0, b = 0;
	for (char c : s) {
		if (c == 'L') a--;
		if (c == 'R') a++;
		if (c == 'U') b--;
		if (c == 'D') b++;
	}
	a = abs(a) + abs(b);
	if (a % 2 != 0) puts("-1");
	else printf("%d\n", a / 2);
	return 0;
}