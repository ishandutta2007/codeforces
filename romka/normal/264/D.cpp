#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

char s[1000010], t[1000010];
int beg[1000010], end[1000010];
vector<int> pos[9];
ll ans;

int cc(char a) {
	if (a == 'R') return 0;
	if (a == 'G') return 1;
	return 2;
}

int getcode(char a, char b) {
	return cc(a) * 3 + cc(b);
}

void go(char* s, char* t, int* beg, bool flag) {
	int n = strlen(s);
	int m = strlen(t);
	int j = 0;
	int pp = 0;
	forn(i, n) {
		if (j == m) break;
		if (s[i] != t[j]) continue;
		if (flag) {
			for (int q = pp; q <= i; q++) beg[q] = j;
			pp = i + 1;
		}
		else
			beg[j] = i;
		ans += n - i - 1;
		j++;
	}
	if (flag) {
		// if (j < m) {
			for (int q = pp; q < n; q++) beg[q] = j;
		// }
	} else {
		for (; j < m; j++)
			beg[j] = n - 1;
	}
}

int main() {
	scanf("%s", s);
	scanf("%s", t);
	go(s, t, beg, true);
	go(t, s, end, false);
	ll n = strlen(s);
	// forn(i, n) printf("%d - %d\n", beg[i], end[i]);
	ll m = strlen(t);

	forn(i, m-1) {
		pos[getcode(t[i], t[i+1])].pb(i);
	}

	for (int i = 1; i < (int)n; i++) {
		if (s[i] == s[i-1]) continue;
		int code = getcode(s[i], s[i-1]);
		int l = lower_bound(pos[code].begin(), pos[code].end(), beg[i] - 1) - pos[code].begin();
		int r = lower_bound(pos[code].begin(), pos[code].end(), end[i]) - pos[code].begin();
		if (r > l) ans += r - l;
	}

	cout << n * m - ans << endl;
	return 0;
}