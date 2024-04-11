
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

const int N = (int) 1e5 + 5, mod = (int) 998244353;
int pw[20], len[20], res;
string s[N];
int main() {
	pw[0] = 1;
	for (int j = 1; j < 20; ++j) pw[j] = (LL) pw[j - 1] * 10 % mod;
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> s[j], len[(int) s[j].size()]++;
	for (int pos = 0; pos < n; ++pos) {
		for (int dig = 0; dig < (int) s[pos].size(); ++dig) {
			int d = s[pos][(int) s[pos].size() - dig - 1] - '0';
			// second
			for (int lo = 1; lo <= 10; ++lo) {
				int add = min(lo, dig);
				res = (res + pw[add + dig] * (LL) d % mod * len[lo]) % mod;
			}
			// first
			for (int lo = 1; lo <= 10; ++lo) {
				int add = min(lo, dig + 1);
				res = (res + pw[add + dig] * (LL) d % mod * len[lo]) % mod;
			}
		}
	}
	cout << res << endl;
}