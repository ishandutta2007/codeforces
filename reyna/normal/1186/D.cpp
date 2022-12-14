
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
long long a[N], choice[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		
		double cur;
		cin >> cur;
		cur *= 100000;
		int ms = 1;
		if (cur < 0) {
			ms = -1;
			cur = -cur;
		}
		long long s = (long long) abs(cur);
		long long rad = s % 100000, dec = s / 100000;
		if (rad == 0) {
			a[j] = (ms >= 0 ? dec : -dec);
			choice[j] = 0;
		} else {
			choice[j] = 1;
			if (ms >= 0) {
				a[j] = dec;	
			} else {
				a[j] = -dec - 1;	
			}
		}
	}
	long long sum = 0;
	for (int j = 0; j < n; ++j) {
		sum += a[j];	
	}
	for (int j = 0; j < n; ++j) {
		if (sum < 0 && choice[j]) {
			a[j]++;
			sum++;
		}
	}
	for (int j = 0; j < n; ++j) {
		cout << a[j] << '\n';
	}
}