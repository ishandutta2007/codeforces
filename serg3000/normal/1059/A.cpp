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
	int n, l, a;
	cin >> n >> l >> a;
	vector<int>tin(n);
	vector<int>tout(n);
	for (int i = 0; i < n; i++) {
		cin >> tin[i];
		cin >> tout[i];
	}
	for (int i = 0; i < n; i++) {
		tout[i] = tin[i] + tout[i];
	}
	tin.push_back(l);
	tout.push_back(0);
	for (int i = n; i > 0; i--) {
		tout[i] = tout[i - 1];
	}
	tout[0] = 0;
	long long cnt = 0;
	for (int i = 0; i < n + 1; i++) {
		cnt += (-tout[i] + tin[i]) / a;
	}
	
	cout << cnt;
	return 0;
}