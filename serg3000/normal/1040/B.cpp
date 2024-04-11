#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	if (n <= 2 * k + 1) {
		cout << 1 << '\n';
		cout << (n + 1) / 2;
		return 0;
	}
	int x = n % (2 * k + 1);
	int y = n / (2 * k + 1);
	if (x >= k + 1) {
		cout << y + 1 << '\n';
		cout << x - k << " ";
		for (int i = 1; i <= y; i++) {
			cout << x - k + i * (k + k + 1) << " ";
		}
	}
	else {
		if (x == 0) {
			cout << y << '\n';
			for (int i = 0; i < y; i++) {
				cout << k + 1 + i * (2 * k + 1) << " ";
			}
		}
		else {
			cout << y + 1 << '\n';
			cout << n << " ";
			x += k;
			x = x % (2 * k + 1);
			cout << x - k << " ";
			for (int i = 1; i < y; i++) {
				cout << x - k + i * (k + k + 1) << " ";
			}
		}
	}
	return 0;
}