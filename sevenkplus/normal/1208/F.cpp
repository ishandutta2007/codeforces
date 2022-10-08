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

#define L 21
#define N 2100000
int n, a[N], f[N];

void upd(int x, int y) {
	if (f[x] >= 2) return;
	if (y == L) {
		f[x] ++;
		return;
	}
	upd(x, y+1);
	if ((x>>y)&1) upd(x^(1<<y), y+1);
}

int ask(int x) {
	int S = 0;
	for (int i = L-1; i >= 0; i--)
		if (~(x>>i)&1) {
			if (f[S^(1<<i)] >= 2) S ^= (1<<i);
		}
	return x^S;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	int S = 0;
	for (int i = n-1; i >= 0; i--) {
		S = max(S, ask(a[i]));
		upd(a[i], 0);
	}
	printf("%d\n", S);
	return 0;
}