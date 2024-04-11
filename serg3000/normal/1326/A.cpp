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
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		string ans;
		int n;
		cin >> n;
		if (n == 1) {
			cout << -1 << '\n';
			continue;
		}
		if (n % 3 != 1) {
			for (int i = 0; i < n - 1; i++) {
				ans.push_back('2');
				
			}
			ans.push_back('3');
		}
		else {
			ans.push_back('4');
			for (int i = 0; i < n - 2; i++) {
				ans.push_back('2');

			}
			ans.push_back('3');
		}
		cout << ans << '\n';
	}


	return 0;
}