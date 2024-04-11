
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

const int N = (int) 1e5 + 5, mod = (int) 0;
int a[N];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) cin >> a[j];
		for (int j = 0; j < n; ++j) {
			a[j] = abs(a[j]);
			if (j & 1) a[j] = -a[j];
			cout << a[j] << ' ';
		}
		cout << '\n';
	}
		
}