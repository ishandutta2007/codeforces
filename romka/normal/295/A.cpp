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

const int maxn = 100010;

int n, m, k;
ll a[maxn], delta[maxn], cnt[maxn];
int l[maxn], r[maxn], d[maxn];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int x, y;
	forn(i, n) scanf("%d", &x), a[i] = x;
	forn(i, m) scanf("%d %d %d", &l[i], &r[i], &d[i]);
	forn(i, k) {
		scanf("%d %d", &x, &y);
		cnt[x-1]++;
		cnt[y]--;
	}
	for (int i = 1; i < m; i++) cnt[i] += cnt[i-1];
	forn(i, m) {
		delta[l[i]-1] += cnt[i] * d[i];
		delta[r[i]] -= cnt[i] * d[i];
	}
	ll dd = 0;
	forn(i, n) {
		dd += delta[i];
		if (i) printf(" ");
		printf("%I64d", a[i] + dd);
	}
	printf("\n");
	return 0;
}