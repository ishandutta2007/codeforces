
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

int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int x, flag = 1;
		cin >> x;
		for (int j = 0; j < n - 1; ++j) {
			int y; 
			cin >> y;
			if (x != y) flag = 0;
		}
		if (flag) {
			cout << n << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
}