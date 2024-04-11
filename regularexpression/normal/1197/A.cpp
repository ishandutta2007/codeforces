#include<algorithm>
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cassert>
#include<chrono>
#include<string>
#include<vector>
#include<random>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<set>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int l = 0, r = *max_element(a.begin(), a.end()) + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			int cnt = 0, kol = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] >= mid + 1) {
					++cnt;
				} else {
					if (a[i] >= 1) {
						++kol;
					}
				}
			}
			if (cnt >= 2 && kol + (cnt - 2) >= mid) {
				l = mid; 
			} else {
				r = mid;
			}
		}
		cout << l << '\n';
	}
	return 0;
}