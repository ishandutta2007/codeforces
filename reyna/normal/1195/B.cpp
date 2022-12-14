
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

const int N = (int) 0, mod = (int) 0;

int main() {
	LL n, k;
	cin >> n >> k;
	swap(n, k);
	for (int put = 0; ; ++put) {
		LL put_in = (LL) (put + 1) * put / 2;
		LL rem = put_in - (k - put);
		if (rem == n) {
			cout << k - put << endl;
			return 0;
		}
	}
}