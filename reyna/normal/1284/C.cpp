
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

const int N = (int) 1e6 + 6;
int f[N];
int main() {
	int n, mod;
	cin >> n >> mod;
	f[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = (LL) f[j - 1] * j % mod;
	int res = 0;
	for (int len = 1; len <= n; ++len) {
		int ways = (n - len + 1) * (LL) (n - len + 1) % mod;
		ways = (LL) ways * f[len] % mod * f[n - len] % mod;
		res = (res + ways) % mod;
	}
	cout << res << endl;
}