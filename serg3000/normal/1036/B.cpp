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
	int q;
	cin >> q;
	long long n, m, k;
	for (int q2 = 0; q2 < q; q2++) {
		cin >> n >> m >> k;
		if (k < max(n, m)) {
			cout << -1 << '\n';
		}
		else {
			if ((n + m) % 2 == 1) {
				cout << k - 1 << '\n';
			}
			else {
				if ((k - max(n, m)) % 2 == 1) {
					cout << k - 2 << '\n';
				}
				else {
					cout << k << '\n';
				}
			}
		}
	}
	
	return 0;
}