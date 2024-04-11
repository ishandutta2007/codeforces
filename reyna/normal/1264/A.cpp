
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int p[N];
int32_t main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> all;
		for (int j = 0; j < n; ++j) {
			cin >> p[j];
		}
		int pt = 0;
		while (pt < n) {
			int cnt = 1;
			while (pt + 1 < n && p[pt] == p[pt + 1]) ++pt, ++cnt;
			all.push_back(cnt);
			++pt;
		}
		int sum_all = 0, sum_cur = 0;
		for (int x : all) sum_all += x;
		sum_cur = sum_all;
		while ((int) all.size() && sum_cur + sum_cur > sum_all) {
			sum_cur -= all.back();
			all.pop_back();
		}
		if ((int) all.size() < 3) {
			cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
			continue;
		}
		int g = all[0];
		int r = (int) all.size() - 1;
		int b = 0, s = sum_cur - g;
		while (r > 0 && b <= g) {
			b += all[r];
			s -= all[r];
			--r;
		}
		if (s <= g) {
			cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
			continue;
		}
		cout << g << ' ' << s << ' ' << b << '\n';
			
	}
}