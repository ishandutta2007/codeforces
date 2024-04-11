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
//#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	vector<int>z(20);
	z[0] = 1;
	for (int i = 1; i < 20; i++) {
		z[i] = z[i - 1] * 2;
	}
	for (int w = 0; w < t; w++) {
		string s;
		cin >> s;
		int n = int(s.size());
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			a[i] = s[i] - '0';
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				int i2 = i - 1;
				int c = 0;
				while (i2 > -1) {
					if (a[i2] == 0) {
						c++;
					}
					else {
						break;
					}
					i2--;
				}

				for (int j = 0; j < 20; j++) {
					int cnt = 0;
					if (i + j >= n) {
						break;
					}
					for (int q = j + i; q >= i; q--) {
						if (a[q] == 1) {
							cnt += z[j + i - q];
						}
					}
					if (j + 1 <= cnt && j + 1 + c >= cnt) {
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	

	return 0;
}