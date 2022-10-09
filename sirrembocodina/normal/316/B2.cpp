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

int used[1010], a[1010];
bool can[1010];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n, s;
	cin >> n >> s;
	--s;
	forn (i, n) {
		used[i] = false;
	}
	forn (i, n) {
		cin >> a[i];
		--a[i];
		if (a[i] != -1) {
			used[a[i]] = true;
		}
	}
	forn (i, 1010) {
		can[i] = false;
	}
	can[0] = true;
	forn (i, n) {
		if (used[i]) {
			continue;
		}
		int v = i, len = 0;
		bool fail = false;
		while (v != -1) {
			if (v == s) {
				fail = true;
				break;
			}
			++len;
			v = a[v];
		}
		if (fail) {
			continue;
		}
		ford (i, 1010) {
			if (can[i]) {
				can[i + len] = true;
			}
		}
	}
	int len = 0, v = s;
	while (v != -1) {
		++len;
		v = a[v];
	}
	forn (i, 1010) {
		if (can[i]) {
			cout << i + len << endl;
		}
	}
}