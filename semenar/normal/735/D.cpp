#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#define INF ((long long)1e18)

bool is_prime(long long p) {
	for (int i = 2; i*i <= p; i++) {
		if (p % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	if (n % 2 != 0) {
		if (is_prime(n)) {
			cout << 1;
		}
		else {
			if (is_prime(n - 2)) {
				cout << 2;
			}
			else {
				cout << 3;
			}
		}
	}
	else {
		if (n == 2) {
			cout << 1;
		}
		else {
			cout << 2;
		}
	}
	return 0;
}