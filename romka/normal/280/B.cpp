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

int n, x, tos, st[100010], ans;

void up(int x) {
	if (x > ans) ans = x;
}

int main() {
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &x);
		while (tos > 0 && st[tos] < x) {
			up(x ^ st[tos]);
			tos--;
		}
		if (tos > 0) up(x ^ st[tos]);
		st[++tos] = x;
	}
	printf("%d\n", ans);
	return 0;
}