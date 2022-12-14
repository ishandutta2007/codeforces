
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
int a[N], b[N];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		for (int j = 0; j < n; ++j)
			cin >> b[j];
		sort(a, a + n);
		sort(b, b + n);
		for (int j = 0; j < n; ++j)
			cout << a[j] << ' ';
		cout << '\n';
		for (int j = 0 ; j < n; ++j) {
			cout << b[j] << ' ';
		}
		cout << '\n';
	}
}