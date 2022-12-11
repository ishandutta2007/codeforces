#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>
#include <iomanip>

using namespace std;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
	
typedef long long ll;
typedef long double ldb;

const int MAXN = 210;

int n;
int f[MAXN];
int d[MAXN];

ll ans = 1;
int maxd = -1;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

void dfs(int v) {
	d[v] = -2;

	if (d[f[v]] == -1) {
		dfs(f[v]);
		if (d[v] == -2)
			d[v] = d[f[v]] + 1;
	} else if (d[f[v]] == -2) {
		int u = f[v];
		int len = 1;
		d[u] = 0;
		while (u != v) {
			u = f[u];
			d[u] = 0;
			len++;
		}

		ans = lcm(ans, len);
	} else {
		d[v] = d[f[v]] + 1;
	}

	maxd = max(maxd, d[v]);
}

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &f[i]);
		f[i]--;
	}

	memset(d, -1, sizeof(d));

	forn(i, n)
		if (d[i] == -1)
			dfs(i);

	ll k = 1;

	while (k * ans < maxd)
		k++;

	cout << k * ans << '\n';

	return 0;
}