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


	int n, d, m;
	cin >> n >> d >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (x + y >= d && x + y <= n + n - d && abs(x - y) <= d) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}