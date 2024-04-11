
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
int a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];	
	}
	int c0 = 0, c1 = 0;
	for (int j = 0; j < n; ++j) {
		if (a[j] % 2 == 0) {
			cout << a[j] / 2 << '\n';	
		} else {
			if (a[j] < 0) {
				int x = -a[j];
				if (c0 == 0) {
					cout << -(x / 2) << '\n';
				} else {
					cout << -(x / 2 + 1) << '\n';
				}
				c0 ^= 1;
			} else {
				int x = a[j];
				if (c1 == 0) {
					cout << x / 2 << '\n';
				} else {
					cout << x / 2 + 1 << '\n';
				}
				c1 ^= 1;
			}
		}
	}
	
}