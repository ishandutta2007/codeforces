
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

const int N = (int) 105, mod = (int) 0;
int a[N];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
		}
		int cost = 0, cnt = 0;
		for (int j = 0; j < n; ++j) {
			while (a[j] > 0 && cost + j <= d) {
				cnt += 1;
				cost += j;
				--a[j];
			}
		}
		cout << cnt << '\n';
	}
}