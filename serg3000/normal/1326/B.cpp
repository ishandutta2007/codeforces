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
mt19937 rnd(time(nullptr));
#define int long long
#define all(v) v.begin(), v.end()
signed main() {
	int n;
	cin >> n;
	vector<int>b(n), a(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = b[i] + mx;
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}