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

unsigned u1, u2, u3, u4, a[100010], b[100010];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	forn(i, n) {
		scanf("%u.%u.%u.%u", &u1, &u2, &u3, &u4);
		a[i] = (u1 << 24) + (u2 << 16) + (u3 << 8) + u4;
	}
	for (int z = 1; z < 32; z++) {
		unsigned mask = (1u << z) - 1;
		mask <<= 32 - z;

		forn(i, n) b[i] = a[i] & mask;

		sort(b, b+n);
		if (unique(b, b+n) - b == k) {
			printf("%u.%u.%u.%u\n", mask >> 24, (mask >> 16) & 255, (mask >> 8) & 255, mask & 255);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}