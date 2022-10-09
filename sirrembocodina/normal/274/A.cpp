#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

int64 a[100100];
bool used[100100];

int main() {
	int n;
	int64 k;
	cin >> n >> k;
	forn (i, n) {
		cin >> a[i];
		used[i] = false;
	}
	sort(a, a + n);
	int ans = 0;
	forn (i, n) {
		if (used[i]) {
			continue;
		}
		++ans;
		int j = lower_bound(a, a + n, a[i] * k) - a;
		if (j < n && a[j] == a[i] * k) {
			used[j] = true;
		}
	}
	cout << ans << endl;
}