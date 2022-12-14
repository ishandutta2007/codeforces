
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
int cnt[20];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		for (int i = 0; i < 20; ++i)
			if (x >> i & 1)
				++cnt[i];
	}
	long long res = 0;
	for (int j = 0; j < n; ++j) {
		int cur = 0;
		for (int i = 0; i < 20; ++i)
			if (cnt[i]) {
				--cnt[i];
				cur |= 1 << i;
			}
		res += (long long) cur * cur;
	}
	cout << res << endl;
}