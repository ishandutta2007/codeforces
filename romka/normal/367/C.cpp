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

int n, m;
pii a[100010];

int main() {
	scanf("%d %d", &n, &m);
	forn(i, m) {
		scanf("%d %d", &a[i].second, &a[i].first);
	}
	sort(a, a+m);
	reverse(a, a+m);

	ll cost = 0;
	ll ans = 0;
	forn(i, m) {
		int v = i + 1;
		cost += a[i].first;
		int extra = 0;
		if (v % 2 == 0)
			extra = v / 2 - 1;
		if ((ll)v * (v - 1) / 2 + extra + 1 <= n)
			ans = cost;
	}

	cout << ans << endl;

	return 0;
}