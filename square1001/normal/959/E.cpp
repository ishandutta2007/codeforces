#include <iostream>
using namespace std;
int main() {
	long long n;
	cin >> n; --n;
	long long ret = 0;
	for (int i = 0; n > 0; ++i) {
		ret += n << (i == 0 ? i : i - 1);
		n >>= 1;
	}
	cout << ret << '\n';
	return 0;
}