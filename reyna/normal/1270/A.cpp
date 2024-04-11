
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

const int N = (int) 0, mod = (int) 0;
int a[10006];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k0, k1;
		cin >> n >> k0 >> k1;
		for (int j = 0; j < k0; ++j) cin >> a[j];
		for (int j = k0; j < n; ++j) cin >> a[j];
		int mx = -1, mxpos = -1;
		for (int j = 0; j < n; ++j) {
			if (mxpos == -1 || a[j] > a[mxpos]) {
				mxpos = j;
			}
		}
		if (mxpos < k0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		
		
	}
}