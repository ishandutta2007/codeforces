
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
int px[N], py[N];
int gcd(int x, int y) {
	if (min(x, y) == 0) return x + y;
	return gcd(y, x % y);
}
pair<int, int> f(pair<int, int> cur) {
	int g = gcd(abs(cur.first), abs(cur.second));
	cur.first /= g;
	cur.second /= g;
	if (cur.first < 0) {
		cur.first *= -1;
		cur.second *= -1;
	}
	return cur;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> px[j] >> py[j];
	if (n % 2 == 1) {
		cout << "NO\n";
		return 0;
	}
	for (int j = n; j < 2 * n; ++j) {
		px[j] = px[j - n], py[j] = py[j - n];
	}
	for (int j = 0; j < n / 2; ++j) {
		int i = j + n / 2;
		pair<int, int> A = make_pair(px[j + 1] - px[i], py[j + 1] - py[i]);
		pair<int, int> B = make_pair(px[j] - px[i + 1], py[j] - py[i + 1]);
		if (f(A) != f(B)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}