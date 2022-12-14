
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

const int N = (int) 10, mod = (int) 0;
int a[N];
int main() {
	int q;
	cin >> q;
	while (q--) {
		char c;
		cin >> c;
		if (c == 'L') {
			for (int j = 0; j < 10; ++j)
				if (!a[j]) {
					a[j] = 1;
					break;
				}
		} else if (c == 'R') {
			for (int j = 9; j >= 0; --j) {
				if (!a[j]) {
					a[j] = 1;
					break;
				}
			}
		} else {
			a[c - '0'] = 0;	
		}
	}
	for (int j = 0; j < 10; ++j)
		cout << a[j];
	
}