#include <iostream>
#include <algorithm>
using namespace std;

long long get(long long n) {
	long long s = 0;
	while (n) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	// your code goes here
	long long n;
	cin >> n;
	long long m = sqrt((double)(n));
	const long long maxD = 110000;
	for (long long i = max(1LL, m - maxD); i <= m + maxD; ++i) {
		if (i * (i + get(i)) == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}