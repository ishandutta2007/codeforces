#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
long long n;
int main() {
	cin >> n;
	long long mul = 1, ret = 1LL << 60;
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= 9; j++) {
			long long r = mul * j;
			if (r > n) ret = min(ret, r - n);
		}
		mul *= 10;
	}
	cout << ret << endl;
	return 0;
}