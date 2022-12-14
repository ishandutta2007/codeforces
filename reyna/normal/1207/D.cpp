
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

const int N = (int) 1e6 + 6, mod = (int) 998244353;
pair<int, int> sr[N];
int f[N];
int main() {
	f[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = (LL) f[j - 1] * j % mod;
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> sr[j].first >> sr[j].second;
	}
	sort(sr, sr + n);
	int both_sorted = 1, cnt = 0, both = 1, left = 1, right = 1;
	for (int j = 0; j < n; ++j) {
		++cnt;
		if (j + 1 == n || sr[j] != sr[j + 1]) {
			both = (LL) both * f[cnt] % mod;
			cnt = 0;
		}
	}	
	for (int j = 0; j < n - 1; ++j)
		if (sr[j].second > sr[j + 1].second)
			both_sorted = 0;
	cnt = 0;
	for (int j = 0; j < n; ++j) {
		++cnt;
		if (j + 1 == n || sr[j].first != sr[j + 1].first) {
			left = (LL) left * f[cnt] % mod;
			cnt = 0;
		}
	}
	for (int j = 0; j < n; ++j) swap(sr[j].first, sr[j].second);
	sort(sr, sr + n);
	cnt = 0;
	for (int j = 0; j < n; ++j) {
		++cnt;
		if (j + 1 == n || sr[j].first != sr[j + 1].first) {
			right = (LL) right * f[cnt] % mod;
			cnt = 0;
		}
	}
	int res = f[n];
	res = (res - left + mod) % mod;
	res = (res - right + mod) % mod;
	res = (res + both * both_sorted) % mod;
	cout << res << endl;

}