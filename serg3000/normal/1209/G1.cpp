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
	int n, q;
	cin >> n >> q;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>la(200100, -1);
	vector<int>col(200100);
	for (int i = n - 1; i > -1; i--) {
		if (la[a[i]] == -1) {
			la[a[i]] = i;
		}
		col[a[i]]++;
	}
	int ans = 0;
	int last = 0;
	int z = 0;
	for (int i = 0; i < n; i++) {
		if (i > last) {
			int ma = 0;
			for (int j = z; j <= last; j++) {
				ma = max(ma, col[a[j]]);
			}
			ans += last - z + 1 - ma;
			z = last + 1;
		}
		if (la[a[i]] > last) {
			last = la[a[i]];
		}
	}
	int ma = 0;
	for (int j = z; j <= last; j++) {
		ma = max(ma, col[a[j]]);
	}
	ans += last - z + 1 - ma;
	z = last + 1;
	cout << ans;
	return 0;
}