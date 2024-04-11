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
	int t;
	cin >> t;
	long long a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int r = 0;
		if (b != a - 1) {
			cout << "NO" << '\n';
			continue;
		}
		else {
			long long p = a + b;
			for (int i = 2; i <= sqrt(p); i++) {
				if (p % i == 0) {
					r = 1;
				}
			}
		}
		if (r == 1) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
	return 0;

}