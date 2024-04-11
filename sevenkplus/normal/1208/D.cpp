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

#define N 200010
int n;
ll a[N];
int S[N];
ll f[N*4];
ll g[N*4];

void blt(int p, int l, int r) {
	if (l == r-1) {
		f[p] = (ll)l*(l+1)/2;
		return;
	}
	int mid = (l+r)/2;
	if (l < mid) blt(p*2+1, l, mid);
	if (mid < r) blt(p*2+2, mid, r);
	f[p] = min(f[p*2+1], f[p*2+2]);
}

int ask(int p, int l, int r, ll s) {
	// printf("A %d %d %d %lld %lld %lld\n", p, l, r, s, f[p], g[p]);
	if (l == r-1) return l;
	if (g[p]) {
		f[p*2+1] -= g[p];
		g[p*2+1] += g[p];
		f[p*2+2] -= g[p];
		g[p*2+2] += g[p];
		g[p] = 0;
	}
	int mid = (l+r)/2;
	if (f[p*2+2] > s) return ask(p*2+1, l, mid, s);
	else return ask(p*2+2, mid, r, s);
}

void upd(int p, int l, int r, int L, int R, int s) {
	if (L <= l && r <= R) {
		f[p] -= s;
		g[p] += s;
		return;
	}
	if (g[p]) {
		f[p*2+1] -= g[p];
		g[p*2+1] += g[p];
		f[p*2+2] -= g[p];
		g[p*2+2] += g[p];
		g[p] = 0;
	}
	int mid = (l+r)/2;
	if (L < mid) upd(p*2+1, l, mid, L, R, s);
	if (mid < R) upd(p*2+2, mid, r, L, R, s);
	f[p] = min(f[p*2+1], f[p*2+2]);
	// printf("U %d %d %d %d %d %d %lld\n", p, l, r, L, R, s, f[p]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	blt(0, 0, n);
	for (int i = n-1; i >= 0; i--) {
		S[i] = ask(0, 0, n, a[i]);
		if (S[i]+1 < n) upd(0, 0, n, S[i]+1, n, S[i]+1);
	}
	for (int i = 0; i < n; i ++)
		printf("%d%c", S[i]+1, i == n-1?'\n': ' ');
	return 0;
}