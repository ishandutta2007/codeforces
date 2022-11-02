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

int n, k, a[100010], f[100010];
map<int, int> mm;

int main() {
	scanf("%d %d", &n, &k);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int ans = 0;
	for (int i = n-1; i>=0; i--) {
		if (a[i] * (ll)k <= a[n-1]) {
			if (mm.find(a[i] * k) != mm.end()) {
				int j = mm[a[i] * k];
				ans -= (f[j] + 1) / 2;
				f[i] = f[j] + 1;
				ans += (f[i] + 1) / 2;
			} else {
				mm[ a[i] ] = i;
				f[i] = 1;
				ans++;
			}
		} else {
			mm[ a[i] ] = i;
			f[i] = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}