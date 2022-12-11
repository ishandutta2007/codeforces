#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)51;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

ll dp[N][N * N + 1][N][2];

pair<int, int> decode(int x) {
	return {x / N, x % N};
}

int code(int L, int R) {
	return L * N + R;
}

int nxt[N][N][2];
int nxtSuf[N][2];
bool isOk[N * N][N];

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int m = s.length();

	for (int l = 0; l < m; l++) {
		for (int r = l; r <= m; r++) {
			for (int z = 0; z < 2; z++) {
				string kek = (r == l ? "" : s.substr(l, r - l)) + char('0' + z);
				int cod = 0;
				for (int l2 = 0; l2 < m; l2++) {
					int r2 = l2 + kek.length();
					if (r2 <= n && s.substr(l2, r2 - l2) == kek && cod == 0) {
						cod = code(l2, r2);
					}					
				}
				nxt[l][r][z] = cod;
			}
		}
	}	

	for (int len = 0; len <= m; len++) {
		for (int z = 0; z < 2; z++) {
			string kek = s.substr(0, len) + char('0' + z);
			int ans = 0;
			int klen = kek.length();
			for (int len2 = 1; len2 <= klen; len2++) {
				if (kek.substr(klen - len2, len2) == s.substr(0, len2)) ans = len2;
			}
			nxtSuf[len][z] = ans;
			//printf("nxtSuf[%d][%d] = %d\n", len, z, nxtSuf[len][z]);
		}
	}

	dp[0][0][0][0] = 1;
	ll ans = 0;

	for (int code = 0; code < N * N; code++) {
		for (int suf = 0; suf <= m; suf++) {
			isOk[code][suf] = false;
			int l = code / N;
			int r = code % N;
			if (r <= l || r > m) continue;

			string kek = s.substr(0, suf) + s.substr(l, r - l);

			isOk[code][suf] = (kek.find(s) != string::npos);
			//cerr << l << " " << r << " " << suf << " " << kek << " " << (int)isOk[code][suf] << "\n";
		}
	}
	isOk[0][m] = true;

	for (int len = 0; len <= n; len++) {
		for (int code = 0; code < N * N; code++) {
			int l = code / N;
			int r = code % N;
			if (r <= l && l + r > 0) continue;

			for (int suf = 0; suf <= min(len, m); suf++) {
				for (int isIn = 0; isIn < 2; isIn++) {
					ll curDp = dp[len][code][suf][isIn]; 
					if (curDp == 0) continue;

					//if (D) printf("len = %d, l = %d, r = %d, suf = %d, in = %d, val = %d\n", len, l, r, suf, (int)isIn, curDp);

					if ((isIn || isOk[code][suf]) && len == n) {
						ans += curDp;
						continue;
					}

					for (int z = 0; z < 2; z++) {
						int newSuf = nxtSuf[suf][z];
						int newIn = min(1, isIn + (int)(newSuf == m));
						
						int newCode = 0;
						if (r - l == len && len < m && nxt[l][r][z] > 0) newCode = nxt[l][r][z];
						else newCode = code;

						dp[len + 1][newCode][newSuf][newIn] += curDp;
					}
				}
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}