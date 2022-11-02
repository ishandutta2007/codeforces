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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int>a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (a[n - i - 1] == 1) {
				cout << -1;
				return 0;
			}
			else {
				if (a[n - i - 1] == 2) {
					cnt += x;
					a[n - i - 1] = 0;
				}
			}
		}
		else {
			if (a[i] == 1) {
				if (a[n - i - 1] == 0) {
					cout << -1;
					return 0;
				}
				else {
					if (a[n - i - 1] == 2) {
						cnt += y;
						a[n - i - 1] = 1;
					}
				}
			}
			else {
				if (a[n - i - 1] == 2 && i != n - i - 1) {
					a[i] = 0;
					a[n - i - 1] == 0;
					cnt += 2 * (min(x, y));
				}
				if (i == n - i - 1) {
					cnt += min(x, y);
				}
			}
		}
	}
	cout << cnt;

	return 0;
}