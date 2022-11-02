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
int main() {
	int n;
	cin >> n;
	vector<int>a(26);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[s[0] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans += a[i] * (a[i] - 1) / 2 - a[i] / 2 * ((a[i] + 1) / 2);
	}
	cout << ans;

	return 0;
}