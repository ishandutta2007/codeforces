#include <iostream>
#include <cstdio>
using namespace std;

int n, m;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = n + 1; i < m; ++i) {
		if (isPrime(i)) {
			cout << "NO";
			return 0;
		}
	}
	if (isPrime(m)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}