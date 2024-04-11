
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
	int tc;
	cin >> tc;
	while (tc--) {
		string x, y;
		cin >> x >> y;
		reverse(ALL(x));
		reverse(ALL(y));
		int n = (int) x.size();
		int st = 0;
		while (y[st] == '0') ++st;
		int ed = st;
		while (x[ed] == '0') ++ed;
		int shift = ed - st;
		cout << shift << '\n';
	}
}