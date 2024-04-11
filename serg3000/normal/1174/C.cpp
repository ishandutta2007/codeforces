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
	vector<int>a(n + 1);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) {
			cnt++;
			int x = i;
			while (x <= n) {
				if (a[x] == 0) {
					a[x] = cnt;
				}
				x += i;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}