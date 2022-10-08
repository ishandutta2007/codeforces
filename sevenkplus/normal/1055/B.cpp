#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int n, m, l;
ll a[N];

bool ff(int x) {
	return (a[x] > l && (x == 0 || a[x-1] <= l));
}

int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; i ++) scanf("%d", a+i);
	int S = 0;
	for (int i = 0; i < n; i ++)
		S += ff(i);
	for (int i = 0; i < m; i ++) {
		int t;
		scanf("%d", &t);
		if (!t) printf("%d\n", S); else {
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			S -= ff(x);
			if (x+1 < n) S -= ff(x+1);
			a[x] += y;
			S += ff(x);
			if (x+1 < n) S += ff(x+1);
		}
	}
	return 0;
}