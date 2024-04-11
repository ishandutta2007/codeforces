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
	long long n, m;
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	if (n > 3) {
		cout << ((n * m / 2) * 2);
	}
	else {
		if (n == 3) {
			
			cout << m * n / 2 * 2;
			return 0;
		}
		else {
			if (n == 2) {
				if (m == 2) {
					cout << 0;
					return 0;
				}
				if (m == 3) {
					cout << 4;
					return 0;
				}
				if (m == 7) {
					cout << 12;
					return 0;
				}
				cout << n * m;
			}
			else {
				long long x = m % 6;
				long long c = m / 6 * 6;
				if (x == 4) {
					c += 2;
				}
				if (x == 5) {
					c += 4;
				}
				cout << c;
				return 0;
			}
		}
	}

	return 0;
	
}