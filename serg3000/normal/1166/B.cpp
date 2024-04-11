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
mt19937 rnd(time(NULL));
int main() {
	int n;
	cin >> n;
	int x = -1, y = -1;
	for (int i = 5; i < n; i++) {
		if (n % i == 0 && n / i >= 5) {
			x = i;
			y = n / i;
		}
	}
	if (x == -1) {
		cout << -1;
		return 0;
	}
	vector<vector<char>>a(x, vector<char>(y, '1'));
	map<int, char>mp;
	mp[0] = 'a';
	mp[1] = 'e';
	mp[2] = 'i';
	mp[3] = 'o';
	mp[4] = 'u';
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			a[i][j] = mp[(i + j) % 5];
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i >= 5) {
				a[i][j] = a[i - 5][j];
			}
			else {
				if (j >= 5) {
					a[i][j] = a[i][j - 5];
				}
			}
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << a[i][j];
		}
	}
	return 0;
}