#include <array>
#include <vector>
#include <iostream>
using namespace std;
const int limit = 2000000;
vector<int> prime_divisors(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n != 1) ret.push_back(n);
	return ret;
}
int main() {
	int n, x;
	cin >> n;
	array<bool, limit> ok{};
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (pos != -1) {
			while (ok[pos]) ++pos;
			x = pos;
		}
		else if(ok[x]) {
			while (ok[x]) ++x;
			pos = 2;
		}
		vector<int> ds = prime_divisors(x);
		for (int j : ds) {
			for (int k = j; k < limit; k += j) {
				ok[k] = true;
			}
		}
		cout << x << (i + 1 == n ? '\n' : ' ');
	}
	return 0;
}