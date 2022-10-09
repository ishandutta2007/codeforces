#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <queue>
#include <deque>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef double ld;
typedef long long int64;

int a[100100];

int main() {
	int n, d;
	cin >> n >> d;
	forn (i, n) {
		cin >> a[i];
	}
	int cur = 0;
	int64 ans = 0;
	forn (i, n) {
		while (a[i] - a[cur] > d) {
			++cur;
		}
		ans += int64(i - cur) * int64(i - cur - 1) / int64(2);
	}
	cout << ans << endl;
}