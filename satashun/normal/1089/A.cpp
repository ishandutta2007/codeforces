#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

#define rep(i,n) for (int i = 0; i < (int)n; ++i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define se second

pair<int, pii> pre[6][6][210][210];

int main() {
	rep(i, 6) rep(j, 6) rep(k, 210) rep(l, 210) pre[i][j][k][l] = mp(-1, mp(-1, -1));

	pre[0][0][0][0] = mp(0, mp(0, 0));

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int nx = (i + j);

			for (int k = 0; k <= 200; ++k) {
				for (int l = 0; l <= 200; ++l) {
					if (pre[i][j][k][l] == mp(-1, mp(-1, -1))) continue;
					int nd = (nx == 4 ? 15 : 25);

					for (int ad = nd; ; ++ad) {//(ad,ad-2)
						if (ad + k > 200 && ad + l > 200) break;
						if (ad + k <= 200 && ad + l - 2 <= 200) {
							pre[i+1][j][k+ad][l+ad-2] = mp(0, mp(ad, ad-2));
						}
						if (ad + k - 2 <= 200 && ad + l <= 200) {
							pre[i][j+1][k+ad-2][l+ad] = mp(1, mp(ad-2, ad));
						}
					}
					for (int ad = 0; ad <= nd - 2; ++ad) {
						if (k + nd <= 200 && l + ad <= 200) {
							pre[i+1][j][k+nd][l+ad] = mp(0, mp(nd, ad));
						}
						if (k + ad <= 200 && l + nd <= 200) {
							pre[i][j+1][k+ad][l+nd] = mp(1, mp(ad, nd));
						}						
					}
				}
			}
		}
	}

	int m; scanf("%d", &m);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int md = -5, ni = -1, nj = -1;

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) if (pre[i][j][a][b] != mp(-1, mp(-1, -1))) {
				if (i == 3 || j == 3) {
					if (i - j > md) {
						md = i - j; ni = i; nj = j;
					}
				}
			}
		}
		if (md == -5) {
			puts("Impossible");
			continue;
		}
		printf("%d:%d\n", ni, nj);
		int num = ni + nj;

		vector<pii> vec;
		while (!(ni == 0 && nj == 0)) {
			auto t = pre[ni][nj][a][b];
			vec.pb(mp(t.se.fi, t.se.se));
			if (t.fi == 0) {
				--ni;
			} else {
				--nj;
			}
			a -= t.se.fi; b -= t.se.se;
		}
		reverse(vec.begin(), vec.end());
		rep(i, num) printf("%d:%d%c", vec[i].fi, vec[i].se, i == num-1 ? '\n' : ' ');
	}

	return 0;
}