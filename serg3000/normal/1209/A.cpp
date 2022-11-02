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
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int>b(n);
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			c++;
			for (int j = 0; j < n; j++) {
				if (a[j] % a[i] == 0) {
					b[j] = 1;
				}
			}
		}
	}
	cout << c;
	return 0;
}