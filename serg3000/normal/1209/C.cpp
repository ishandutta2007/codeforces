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
#define int long long
signed main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n;
		cin >> n;
		string d;
		cin >> d;
		int la = 0;
		vector<int>b(n, 2);
		int f = 0;
		for (int x = 0; x <= 9; x++) {
			vector<int>a;
			for (int i = 0; i < n; i++) {
				if (b[i] == 1) {
					a.push_back(d[i] - '0');
				}
			}
			for (int i = 0; i < n; i++) {
				if (b[i] == 2) {
					a.push_back(d[i] - '0');
				}
			}
			int z = 0;
			for (int i = 0; i < n - 1; i++) {
				if (a[i] > a[i + 1]) {
					z = 1;
					break;
				}
			}
			if (z == 0) {
				for (int i = 0; i < n; i++) {
					cout << b[i];
				}
				cout << '\n';
				f = 1;
				break;
			}
			
			for (int i = la; i < n; i++) {
				if (d[i] - '0' == x) {
					b[i] = 1;
					la = i;
				}
			}
		}
		if (f == 0) {
			vector<int>a;
			for (int i = 0; i < n; i++) {
				if (b[i] == 1) {
					a.push_back(d[i] - '0');
				}
			}
			for (int i = 0; i < n; i++) {
				if (b[i] == 2) {
					a.push_back(d[i] - '0');
				}
			}
			int z = 0;
			for (int i = 0; i < n - 1; i++) {
				if (a[i] > a[i + 1]) {
					z = 1;
					break;
				}
			}
			if (z == 0) {
				for (int i = 0; i < n; i++) {
					cout << b[i];
				}
			}
			else {
				cout << "-";
			}
			cout << '\n';
		}
	}
	return 0;
}