#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	while (true) {
		for (int i = 1; i <= n; ++i) {
			if (m < i) {
				cout << m << endl;
				return 0;
			}
			m -= i;
		}
	}

	return 0;
}