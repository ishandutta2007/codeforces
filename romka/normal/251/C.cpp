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

const int lcm = 360360;
int d[3 * lcm + 3];

int main() {
	ll a, b;
	int k;
	cin >> a >> b >> k;
	memset(d, 0xff, sizeof(d));
	d[0] = 0;
	int lim = 3 * lcm;
	forn(i, lim + 1)
		if (d[i] != -1) {
			ll v = a - i;
			for (int x = 2; x <= k; x++) {
				ll nv = v - (v % x);
				int j = a - nv;
				if (j <= lim && (d[j] == -1 || d[j] > d[i] + 1))
					d[j] = d[i] + 1;
			}
			if (d[i+1] == -1 || d[i+1] > d[i] + 1) d[i+1] = d[i] + 1;
		}
	if (a - b <= lim) {
		printf("%d\n", d[a - b]);
		return 0;
	}
	set<int> ss;
	forn(i, lcm) ss.insert(d[lim - i] - d[lim - lcm - i]);
	// printf("size = %d\n", ss.size());
	int diff = d[lim] - d[lim - lcm];
	ll dd = a - b;
	ll cnt = dd / lcm;
	dd -= (cnt - 2) * lcm;
	cout << d[dd] + (cnt - 2) * diff << endl;
    return 0;
}