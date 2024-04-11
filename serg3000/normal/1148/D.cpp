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
	vector<vector<int>>one;
	vector<vector<int>>two;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			one.push_back({ b, a, i });
		}
		else {
			two.push_back({ b, a, i });
		}
	}
	sort(one.begin(), one.end());
	sort(two.begin(), two.end());
	int x = one.size();
	int y = two.size();
	if (one.size() >= two.size()) {
		cout << x << '\n';
		for (int i = x - 1; i > -1; i--) {
			cout << one[i][2] + 1 << " ";
		}
	}
	else {
		cout << y << '\n';
		for (int i = 0; i < y; i++) {
			cout << two[i][2] + 1 << " ";
		}
	}
	return 0;
}