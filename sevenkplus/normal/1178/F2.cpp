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

#define P 998244353
#define M 510
#define N 1000010
int m, n;
int a[N];
int b[M][M];
int f[M][M];
int pl[M], pr[M];
int cl[M], cr[M];
int icl[N], icr[N];

int hh(int p);

int ff(int l, int r) {
	if (f[l][r] != -1) return f[l][r];

	int p = b[l][r];
	if (pl[p] < cl[l] || pr[p] > cr[r]) return f[l][r] = 0;

	int S = 0;
	int T = 0;
	for (int k = 0; k < m; k ++)
		if (cl[l] <= cl[k] && cl[k] <= pl[p]) {
			int w = 1;
			if (cl[l] != cl[k]) {
				if (icr[cl[k]-1] == -1) w = 0;
				else w = (ll)w*ff(l, icr[cl[k]-1])%P;
			}
			if (cl[k] != pl[p]) {
				if (icr[pl[p]-1] == -1) w = 0;
				else w = (ll)w*ff(k, icr[pl[p]-1])%P;
			}
			(S += w) %= P;
		}
	
	for (int k = 0; k < m; k ++)
		if (pr[p] <= cr[k] && cr[k] <= cr[r]) {
			int w = 1;
			if (pr[p] != cr[k]) {
				if (icl[pr[p]+1] == -1) w = 0;
				else w = (ll)w*ff(icl[pr[p]+1], k)%P;
			}
			if (cr[k] != cr[r]) {
				if (icl[cr[k]+1] == -1) w = 0;
				else w = (ll)w*ff(icl[cr[k]+1], r)%P;
			}
			(T += w) %= P;
		}
	
	// printf("%d %d %d %d\n", cl[l], cr[r], S, T);

	int U = 1;
	U = (ll)U*S%P;
	U = (ll)U*T%P;
	U = (ll)U*hh(p)%P;

	return f[l][r] = U;
}

int h[M];
vector<int> ch[M];

int hh(int p) {
	if (h[p] != -1) return h[p];
	int S = 1;
	int la = -1;
	for (auto i : ch[p]) {
		if (la != -1 && la+1 <= i-1) {
			if (icl[la+1] == -1) {
				S = 0;
				break;
			}
			if (icr[i-1] == -1) {
				S = 0;
				break;
			}
			S = (ll)S*ff(icl[la+1], icr[i-1])%P;
		}
		la = i;
	}
	return h[p] = S;
}

int g[N*4];
void blt(int p, int l, int r) {
	if (l == r-1) {
		g[p] = a[l];
		return;
	}
	int mid = (l+r)/2;
	blt(p*2+1, l, mid);
	blt(p*2+2, mid, r);
	g[p] = min(g[p*2+1], g[p*2+2]);
}

int ask(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return g[p];
	int S = P;
	int mid = (l+r)/2;
	if (L < mid) S = min(S, ask(p*2+1, l, mid, L, R));
	if (mid < R) S = min(S, ask(p*2+2, mid, r, L, R));
	return S;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(pl, -1, sizeof pl);
	memset(pr, -1, sizeof pr);

	cin >> m >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		a[i] --;
		if (pl[a[i]] == -1 || pl[a[i]] > i) pl[a[i]] = i;
		if (pr[a[i]] == -1 || pr[a[i]] < i) pr[a[i]] = i;
		ch[a[i]].pb(i);
	}

	memcpy(cl, pl, sizeof cl);
	memcpy(cr, pr, sizeof cr);
	sort(cl, cl+m);
	sort(cr, cr+m);

	memset(icl, -1, sizeof icl);
	memset(icr, -1, sizeof icr);
	for (int i = 0; i < m; i ++) {
		icl[cl[i]] = i;
		icr[cr[i]] = i;
	}

	blt(0, 0, n);

	memset(b, -1, sizeof b);

	for (int i = 0; i < m; i ++)
		for (int j = 0; j < m; j ++)
			if (cl[i] <= cr[j])
				b[i][j] = ask(0, 0, n, cl[i], cr[j]+1);
	
	memset(f, -1, sizeof f);
	memset(h, -1, sizeof h);

	cout << ff(0, m-1) << endl;
	return 0;
}