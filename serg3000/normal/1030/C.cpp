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
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int>a(n);
	int c = 0;
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
		c += a[i];
	}
	if (c == 0) {
		cout << "YES";
	}
	else {
		for (int i = 1; i < c; i++) {
			if (c % i == 0) {
				int cnt = 0;
				int j = 0;
				int ch = 0;
				while (1) {
					if (j == n) {
						break;
					}
					cnt += a[j];
					j++;
					if (cnt == i) {
						cnt = 0;
					}
					if (cnt > i) {
						ch = 1;
						break;
					}
				}
				if (ch == 0) {
					cout << "YES";
					return 0;
				}
			}
		}
		cout << "NO";
	}
	return 0;
}