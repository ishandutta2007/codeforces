#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const long long inf = 100000000000LL;

vector < long long > a;
void rec(long long value, int x = 0, int y = 0) {
	if (value > 0 && x == y) {
		a.push_back(value);
	}
	if (value > inf) {
		return;
	}
	rec(value * 10 + 4, x + 1, y);
	rec(value * 10 + 7, x, y + 1);
}

int main() {
	long long n;
	cin >> n;
	rec(0);
	sort(a.begin(), a.end());
	cout << *lower_bound(a.begin(), a.end(), n) << endl;
	return 0;
}