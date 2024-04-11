// ?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll SQ = 450; // check

int F[SQ + 10][SQ + 10], X[MAXN], Y[MAXN], T[MAXN], n, q, A[MAXN], ind[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i];
		T[i] = (X[i] + Y[i] < SQ);
	}

	int ans = 0, tot = 0;
	for (int d = 1; d <= q; d++) {
		int c, k;
		cin >> c >> k;
		if (c == 2) c = -1;
		tot += c;

		int s = X[k] + Y[k];
		if (c == 1) ind[k] = d;

		if (c) {
			if (T[k]) {
				F[s][ind[k] % s] += c;
				F[s][(ind[k] + X[k]) % s] -= c;
			} else {
				for (int i = ind[k]; i < MAXN; i += s) {
					A[i] += c;
					if (i + X[k] < MAXN) A[i + X[k]] -= c;
				}	
			}

			if (c == -1) {
				if ((d - 1 - ind[k]) % s < X[k]) {
					ans--;
				}
			}
		}

		for (int i = 1; i <= SQ + 2; i++) {
			ans += F[i][d % i];
		}

		ans += A[d];

		cout << tot - ans << endl;
	}
	return 0;
}