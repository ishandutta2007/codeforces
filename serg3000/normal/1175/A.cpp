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
mt19937 rnd(time(NULL));
#define int long long
signed main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		while (n != 0) {
			cnt += n % k;
			n /= k;
			cnt++;
		}
		cnt--;
		cout << cnt << '\n';
	}

	return 0;
}