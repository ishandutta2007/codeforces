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
	double s;
	cin >> s;
	vector<vector<int>>g(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1) {
			cnt++;
		}
	}
	cout.precision(15);
	cout << s / cnt * 2;
	return 0;
}