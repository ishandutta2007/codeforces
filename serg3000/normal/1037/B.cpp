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
	int n, s;
	cin >> n >> s;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int i1 = n;
	for (int i = 0; i < n; i++) {
		if (a[i] >= s) {
			i1 = i;
			break;
		}
	}
	long long cnt = 0;
	if (i1 > (n - 1) / 2) {
		for (int i = (n - 1) / 2; i < i1; i++) {
			cnt += s - a[i];
		}
		cout << cnt;
	}
	else {
		for (int i = i1; i < (n - 1) / 2 + 1; i++) {
			cnt += a[i] - s;
		}
		cout << cnt;
	}
	return 0;
}