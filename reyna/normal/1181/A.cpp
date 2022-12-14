
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
	long long x, y, z;
	cin >> x >> y >> z;
	if (x / z + y / z == (x + y) / z) {
		cout << (x + y) / z << ' ' << 0 << endl;
		return 0;
	}
	long long res = min(z - y % z, z - x % z);
	cout << (x + y) / z << ' ' << res << endl;
}