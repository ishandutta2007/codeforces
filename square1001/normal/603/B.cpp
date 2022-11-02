#include <vector>
#include <iostream>
using namespace std;
const int modulo = 1000000007;
int p, x;
int main() {
	cin >> p >> x;
	int mul = 1, cnt = 0;
	if (x == 0) cnt = p - 1;
	else if (x == 1) cnt = p;
	else {
		while (cnt == 0 || mul != 1) {
			++cnt;
			mul = 1LL * mul * x % p;
		}
		cnt = (p - 1) / cnt;
	}
	for (int i = 0; i < cnt; ++i) {
		mul = 1LL * mul * p % modulo;
	}
	cout << mul << '\n';
	return 0;
}