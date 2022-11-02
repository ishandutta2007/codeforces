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
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= 1;
		b[a[i]] = i;
	}
	vector<int>ans(n);
	for (int i = n - 1; i > -1; i--) {
		for (int j = b[i] - (n / (i + 1) + 1) * (i + 1); j < n; j += i + 1) {
			if (j >= 0) {
				if (a[j] > i) {
					if (ans[a[j]] == 0) {
						ans[i] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[a[i]] == 0) {
			cout << "B";
		}
		else {
			cout << "A";
		}
	}
	return 0;

}