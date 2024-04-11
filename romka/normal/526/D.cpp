#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

vector<pii> ev;

int n, k;
char s[1000010];
int z[1000010];

void zfunc() {
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r)	z[i] = min(r - i + 1, z[i-l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	zfunc();

	for (int lab = 1; lab * k <= n; lab++) {
		int l2k = lab * k;
		if (z[lab] >= lab * (k - 1)) {
			int c = z[l2k];
			if (lab < c) c = lab;
			ev.push_back(pii(l2k - 1, +1));
			ev.push_back(pii(l2k + c, -1));
		}
	}
	sort(ev.begin(), ev.end());
	size_t ie = 0;
	int balance = 0;
	forn(i, n) {
		while (ie < ev.size() && ev[ie].first == i) {
			balance += ev[ie].second;
			ie++;
		}
		printf("%d", int(balance > 0));
	}
	printf("\n");

	return 0;
}