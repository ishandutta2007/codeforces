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
	vector<int>ans;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (i != sqrt(n)) {
				ans.push_back(n * (n / i - 1) / 2 + n / i);
				int i2 = n / i;
				ans.push_back(n * (n / i2 - 1) / 2 + n / i2);
			}
			else {
				ans.push_back(n * (n / i - 1) / 2 + n / i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}