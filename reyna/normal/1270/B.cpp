
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
int a[N];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int flag = 0, n;
		cin >> n;
		for (int j = 0; j < n; ++j) cin >> a[j];
		for (int j = 0; j < n - 1; ++j) {
			if (abs(a[j] - a[j + 1]) > 1) {
				cout << "YES\n";
				cout << j + 1 << ' ' << j + 2 << '\n';
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
		}
	}
}