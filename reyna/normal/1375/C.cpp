
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
int a[N], s[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		int t = 0;
		for (int j = 0; j < n; ++j) {
			if (t == 0) {
				s[t++] = a[j];
			} else {
				if (s[t-1] < a[j]) {
					while (t > 1 && s[t-1] < a[j]) --t;
					if (t == 1 && s[t - 1] < a[j]) {
						
					} else {
						s[t++] = a[j];
					}
				} else {
					s[t++] = a[j];
				}
			}
		}
		if (t <= 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}