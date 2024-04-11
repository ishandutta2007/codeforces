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

ll a[510][510];
int x[510];
int n;
bool good[510];
vector<ll> ans;

int main() {
	scanf("%d", &n);
	int z;
	forn(i, n) forn(j, n) scanf("%d", &z), a[i][j] = z;
	forn(i, n) scanf("%d", &x[i]);

	for (int q=n-1; q>=0; q--) {
		int k = x[q] - 1;
		good[k] = true;
		ll res = 0;
		forn(i, n)
			forn(j, n) {
				if (a[i][k] + a[k][j] < a[i][j]) a[i][j] = a[i][k] + a[k][j];
				if (good[i] && good[j]) res += a[i][j];
			}
		ans.pb(res);
	}

	for (int i = n-1; i>=0; i--) {
		if (i < n-1) printf(" ");
		printf("%I64d", ans[i]);
	}
	printf("\n");

	return 0;
}