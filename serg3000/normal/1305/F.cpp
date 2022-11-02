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
int MAXN = 1e6;
vector<int>pr;
set<int>z;
void find(int x) {
	for (auto u : pr) {
		while(x % u == 0){
			z.insert(u);
			x /= u;
		}
	}
	if (x != 1) {
		z.insert(x);
	}
}
signed main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>c(MAXN);
	for (int i = 2; i < MAXN; i++) {
		if (c[i] == 0) {
			pr.push_back(i);
			for (int j = i; j < MAXN; j += i) {
				c[j] = 1;
			}
		}
	}
	shuffle(all(a), rnd);
	for (int i = 0; i < min(30ll, n); i++) {
		if (a[i] != 1) {
			find(a[i] - 1);
		}
		find(a[i] + 1);
		find(a[i]);
	}
	int ans = n;

	for (auto u : z) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (cnt < ans) {
				if (a[i] <= u) { cnt += u - a[i]; }
				else {
					cnt += min(a[i] % u, u - (a[i] % u));
				}
				
			}
			else {
				break;
			}
		}
		if (cnt < ans) {
			ans = cnt;
		}
	}
	cout << ans;
	return 0;
}