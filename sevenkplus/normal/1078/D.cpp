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
const PII full(-1, -1);
int n;
PII a[N];

PII f[17][N*4];

// union
PII gg(PII x, PII y) {
	if (x == full) return x;
	if (y == full) return y;
	if (x.fi <= x.se && y.fi <= y.se) {
		PII s(min(x.fi, y.fi), max(x.se, y.se));
		if (s.fi == 0 && s.se == n-1) return full;
		return s;
	}
	int le = 0, ri = n-1;
	if (x.fi > x.se) {
		le = max(le, x.se);
		ri = min(ri, x.fi);
	}
	if (y.fi > y.se) {
		le = max(le, y.se);
		ri = min(ri, y.fi);
	}
	if (x.fi <= x.se) {
		if (x.fi <= le+1) le = max(le, x.se);
		if (x.se >= ri-1) ri = min(ri, x.fi);
	}
	if (y.fi <= y.se) {
		if (y.fi <= le+1) le = max(le, y.se);
		if (y.se >= ri-1) ri = min(ri, y.fi);
	}
	if (le >= ri-1) return full;
	return mp(ri, le);
}

void blt(PII*f, int p, int l, int r) {
	if (l == r-1) {
		f[p] = a[l];
		return;
	}
	int mid = (l+r)/2;
	blt(f, p*2+1, l, mid);
	blt(f, p*2+2, mid, r);
	f[p] = gg(f[p*2+1], f[p*2+2]);
}

PII ask(PII*f, int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return f[p];
	int mid = (l+r)/2;
	if (R <= mid) return ask(f, p*2+1, l, mid, L, R);
	if (L >= mid) return ask(f, p*2+2, mid, r, L, R);
	return gg(ask(f, p*2+1, l, mid, L, R), ask(f, p*2+2, mid, r, L, R));
}

PII ask(PII*f, PII s) {
	if (s == full) return s;
	if (s.fi <= s.se) return ask(f, 0, 0, n, s.fi, s.se+1);
	return gg(ask(f, 0, 0, n, s.fi, n), ask(f, 0, 0, n, 0, s.se+1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (x*2+1 >= n) a[i] = full; else {
			int l = (i-x+n)%n;
			int r = (i+x)%n;
			a[i] = mp(l, r);
		}
	}
	if (n == 1) {
		puts ("0");
		return 0;
	}
	blt(f[0], 0, 0, n);
	for (int l = 1; l <= 16; l ++) {
		// blt f[l] from f[l-1]
		for (int i = 0; i < n; i ++)
			a[i] = ask(f[l-1], a[i]);
		blt(f[l], 0, 0, n);
	}

	for (int i = 0; i < n; i ++) {
		int S = 0;
		PII s = mp(i, i);
		for (int l = 16; l >= 0; l--) {
			PII t = ask(f[l], s);
			if (t != full) {
				S += (1<<l);
				s = t;
			}
		}
		S++;
		cout << S << (i == n-1?'\n':' ');
	}
	return 0;
}