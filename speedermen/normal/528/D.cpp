#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)			int(a.size())
#define all(a)			(a).begin(), (a).end()
#define CL(a, b)		memset(a, b, sizeof a);
#define FOR(i, a, b)	for (int i(a); i < (b); ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(a)			sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb				push_back

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> cd;

const double pi = acos(-1.0);

cd w[1 << 20];

template <class S> void fft(S *p, cd *y, int n, int k = 1) {
	if (n > 1) {
		fft(p, y, n /= 2, k + k);
		fft(p + k, y + n, n, k + k);
		for (int i = 0, j = 0; i < n; ++i, j += k) {
			cd r = w[j] * y[i + n];
			y[i + n] = y[i] - r;
			y[i] += r;
		}
	} else *y = *p;
}

int n, m, k, on, om;
char a[1 << 20], b[1 << 20];
int r[1 << 20];
int p[1 << 20], q[1 << 20];
cd P[1 << 20], Q[1 << 20];
int f[1 << 20], g[1 << 20];

void solve(char c, int l = 1 << 18) {
	REP (i, l) {
		p[i] = b[i] == c;
		q[i] = 0;
	}
	REP (i, n) {
		if(a[i] == c) {
			f[i] = i;
		} else {
			f[i] = (i > 0 ? f[i - 1] : -1);
		}
	}
	g[n] = -1;
	for(int i = n - 1; i >= 0; --i) {
		if(a[i] == c) {
			g[i] = i;
		} else {
			g[i] = g[i + 1];
		}
	}
	for(int i = 0; i < n; ++i) {
		q[i] = 0;
		if(f[i] != -1) {
			if(i - f[i] <= k) q[i] = 1;
		}
		if(g[i] != -1) {
			if(g[i] - i <= k) q[i] = 1;
		}
	}
	REP (i, l) w[i] = polar(1.0, (2 * pi) * i / l);
	fft(p, P, l);
	fft(q, Q, l);
	REP (i, l) {
		w[i] = conj(w[i]);
		P[i] *= Q[i];
	}
	fft(P, Q, l);
	REP (i, l) r[i] += (int)(real(Q[i]) / l + 0.5);
}

int main() {
	cin >> n >> m >> k >> a >> b;
    reverse(b, b + m);
	REP (k, 4) solve("ACGT"[k]);
	int ans = 0;
	FOR (i, m - 1, n) {
		if (r[i] == m) {
			++ans;
		}
	}
	cout << ans << "\n";
	getchar(); getchar();
	return 0;
}