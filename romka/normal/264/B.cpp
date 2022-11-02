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

int n, a[100010], last[100010], f[100010];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	memset(last, 0xff, sizeof(last));
	int ans = 1;
	forn(i, n) {
		f[i] = 1;
		int x = a[i];
		for (int j = 2; j * j <= x; j++) {
			if (x % j) continue;
			if (last[j] != -1)
				f[i] = max(f[i], f[last[j]] + 1);
			last[j] = i;
			while (x % j == 0) x /= j;
		}
		if (x > 1) {
			int j = x;
			if (last[j] != -1)
				f[i] = max(f[i], f[last[j]] + 1);
			last[j] = i;
			while (x % j == 0) x /= j;	
		}
		if (f[i] > ans) ans = f[i];
	}
	printf("%d\n", ans);
	return 0;
}