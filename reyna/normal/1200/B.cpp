
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

const int N = (int) 105, mod = (int) 0;
int a[N];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k, flag = 1;
		cin >> n >> m >> k;
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		for (int cur = 0; flag && cur < n - 1; ++cur) {
			int j = cur;
			int to = max(0, (a[j + 1] - k));
			if (a[j] <= to) {
				m -= to - a[j];
				if (m < 0) {
					cout << "NO\n";
					flag = 0;
					break;
				}
			} else {
				m += a[j] - to;	
			}
		}
		if (flag) {
			cout << "YES\n";
		}
	}
}