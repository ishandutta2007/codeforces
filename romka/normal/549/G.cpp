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

int n, a[200010];

int main() {
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
		a[i] += i;
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		a[i] -= i;
		if (a[i] < a[i-1]) {
			printf(":(\n");
			return 0;
		}
	}
	forn(i, n) printf("%d%c", a[i], " \n"[i == n - 1]);
	return 0;
}