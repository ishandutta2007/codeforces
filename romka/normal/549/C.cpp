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


int solve(int k, int o, int e) {
	if (o + e == k) return o & 1;
	if (k % 2 == 0) {
		if ((o + e) & 1) {
			return abs(o - e) < k;
		} else {
			return 0;
		}
	} else {
		if (o >= e + k) return 1;
		if ((o + e) % 2 == 0) {
			return abs(o - e) < k;
		} else {
			return 0;
		}
	}
}

int main() {
	int n, k, o = 0, e = 0, x;
	scanf("%d %d", &n, &k);
	forn(i, n) {
		scanf("%d", &x);
		if (x & 1) o++;
		else e++;
	}
	if (solve(k, o, e)) printf("Stannis\n");
	else printf("Daenerys\n");
	return 0;
}