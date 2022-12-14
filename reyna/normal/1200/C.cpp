
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
long long gcd(long long a, long long b) {
	if (min(a, b) == 0) return a + b;
	return gcd(b, a % b);
}
long long n, m;
long long g;
long long read() {
	int x;
	cin >> x;
	if (x == 1) {
		long long y;
		cin >> y;
		return (y - 1) / (n / g);
	} else {
		long long y;
		cin >> y;
		return (y - 1) / (m / g);
	}
}
int main() {
	int q;
	cin >> n >> m >> q;
	g = gcd(n, m);
	while (q--) {
		// x / l = x * g / (n * m) 
		long long x = read(), y = read();
		if (x == y) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}