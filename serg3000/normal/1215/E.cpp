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
	vector<int>col(20), z(20);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		col[a[i]]++;
	}
	vector<vector<int>>b(20, vector<int>(20));
	vector<vector<int>>c(20, vector<int>(20));
	for (int i = 0; i < n; i++) {
		z[a[i]]++;
		for (int j = 0; j < a[i]; j++) {
			b[j][a[i]] += z[j];
		}
	}
	for (int i = 0; i < 20; i++) {
		z[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		z[a[i]]++;
		for (int j = 0; j < a[i]; j++) {
			c[j][a[i]] += col[j] - z[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			ans += min(c[i][j], b[i][j]);
		}
	}
	cout << ans;
	return 0;
}