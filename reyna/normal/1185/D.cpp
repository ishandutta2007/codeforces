
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

const int N = (int) 1e6 + 6, mod = (int) 0;
#define int long long
int a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	map<int, int> have;
	int xr = 0;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		xr ^= a[j];
		have[a[j]]++;
		b[j] = a[j];
	}
	if (n < 3) {
		cout << 1 << endl;
		return 0;
	}
	sort(b, b + n);
	for (int st = 0; st < 2; ++st)
		for (int ot = st + 1; ot < 3; ++ot) {
			int d = b[ot] - b[st];
			int start = b[st];
			int flag = 1;
			int s = xr;
			if (d == 0) {
				if (have[start] < n - 1) flag = 0;	
			}
			for (int j = 0; j < n - 1; ++j) {
				s ^= start + (LL) d * j;
				if (have.find(start + (LL) d * j) == have.end())
					flag = 0;
			}
			if (flag) {
				for (int j = 0; j < n; ++j) {
					if (s == a[j]) {
						cout << j + 1 << endl;
						return 0;
					}
				}
				
			}
		}
	cout << -1 << endl;
}