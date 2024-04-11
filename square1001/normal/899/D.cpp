#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	if (n <= 4) cout << n * (n - 1) / 2 << endl;
	else {
		long long mul = 10;
		while (mul * 10 - 1 <= n * 2) mul *= 10;
		long long ret = 0;
		for (int i = 1; i <= 9; i++) {
			long long val = mul * i - 1;
			if (val <= n) ret += val / 2;
			else if(val <= 2 * n) ret += (2 * n + 2 - val) / 2;
		}
		cout << ret << endl;
	}
	return 0;
}