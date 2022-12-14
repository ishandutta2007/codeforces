
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

const int N = (int) 2e5 + 5, mod = (int) 0;
int a[N], b[N], c[N];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	reverse(ALL(s));
	int found0 = 0;
	for (int cur = n / 2 - 1; cur >= 0; --cur) {
		if (s[cur] != '0') {
			for (int i = 0; i <= cur; ++i) {
				a[i] += s[i] - '0';	
			}
			for (int i = cur + 1; i < n; ++i) {
				a[i - cur - 1] += s[i] - '0';
			}
			found0 = 1;
			break;
		}
	}
	int found1 = 0;
	for (int cur = n / 2; cur < n - 1; ++cur) {
		if (s[cur] != '0') {
			for (int i = 0; i <= cur; ++i) {
				b[i] += s[i] - '0';
			}
			for (int i = cur + 1; i < n; ++i) {
				b[i - cur - 1] += s[i] - '0';
			}
			found1 = 1;
			break;
		}
	}
	for (int j = 0; j < N - 1; ++j) {
		a[j + 1] += a[j] / 10; a[j] %= 10;
		b[j + 1] += b[j] / 10; b[j] %= 10;
	}
	int ls = 0;
	for (int j = N - 1; j >= 0; --j) {
		if (a[j] != b[j]) {
			ls = (a[j] < b[j]);
			break;
		}
	}
	if (!found0) {
		ls = 0;	
	}
	if (!found1) {
		ls = 1;
	}
	if (ls) {
		int z = 1;
		for (int j = N - 1; j >= 0; --j) {
			if (a[j] != 0) z = 0;
			if (!z) cout << a[j];
		}
	} else {
		int z = 1;
		for (int j = N - 1; j >= 0; --j) {
			if (b[j] != 0) z = 0;
			if (!z) cout << b[j];
		}
	}
}