#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 100010;
const int maxl = 260;

inline void chmin(int &x, int y) { if (x > y) x = y; }

int nx[30][maxn];
int dp[maxl][maxl][maxl];

int main() {
	int n, q; cin >> n >> q;
	string sx; cin >> sx;

	rep(j, 26) nx[j][n] = n;

	for (int i = n-1; i >= 0; --i) {
		int c = sx[i] - 'a';
		rep(j, 26) nx[j][i] = nx[j][i+1];
		nx[c][i] = i;
	}

	rep(j, maxl) rep(k, maxl) rep(l, maxl) dp[j][k][l] = maxn;

	dp[0][0][0] = 0;

	string s[3];

	rep(i, q) {
		char type, cc = '!';
		int id;
		cin >> type >> id;
		--id;

		if (type == '+') {
			cin >> cc;
			s[id].pb(cc);
			int sl = s[id].size();

			if (id == 0) {
				rep(k, s[1].size()+1) rep(l, s[2].size()+1) {
					if (sl > 0 && dp[sl-1][k][l] < n) {
						int c = s[0].back() - 'a';
						chmin(dp[sl][k][l], nx[c][dp[sl-1][k][l]] + 1);
					}
					if (k > 0 && dp[sl][k-1][l] < n) {
						int c = s[1][k-1] - 'a';
						chmin(dp[sl][k][l], nx[c][dp[sl][k-1][l]] + 1);
					}
					if (l > 0 && dp[sl][k][l-1] < n) {
						int c = s[2][l-1] - 'a';
						chmin(dp[sl][k][l], nx[c][dp[sl][k][l-1]] + 1);
					}
				}
			} else if (id == 1) {
				rep(k, s[0].size()+1) rep(l, s[2].size()+1) {
					if (sl > 0 && dp[k][sl-1][l] < n) {
						int c = s[1].back() - 'a';
						chmin(dp[k][sl][l], nx[c][dp[k][sl-1][l]] + 1);
					}
					if (k > 0 && dp[k-1][sl][l] < n) {
						int c = s[0][k-1] - 'a';
						chmin(dp[k][sl][l], nx[c][dp[k-1][sl][l]] + 1);
					}
					if (l > 0 && dp[k][sl][l-1] < n) {
						int c = s[2][l-1] - 'a';
						chmin(dp[k][sl][l], nx[c][dp[k][sl][l-1]] + 1);
					}
				}			
			} else {
				rep(k, s[0].size()+1) rep(l, s[1].size()+1) {
					if (sl > 0 && dp[k][l][sl-1] < n) {
						int c = s[2].back() - 'a';
						chmin(dp[k][l][sl], nx[c][dp[k][l][sl-1]] + 1);
					}
					if (k > 0 && dp[k-1][l][sl] < n) {
						int c = s[0][k-1] - 'a';	
						chmin(dp[k][l][sl], nx[c][dp[k-1][l][sl]] + 1);
					}
					if (l > 0 && dp[k][l-1][sl] < n) {
						int c = s[1][l-1] - 'a';	
						chmin(dp[k][l][sl], nx[c][dp[k][l-1][sl]] + 1);
					}
				}			
			}
		} else {
			int sl = s[id].size();
			if (id == 0) {
				rep(k, maxl) rep(l, maxl) {
					dp[sl][k][l] = maxn;
				}
			} else if (id == 1) {
				rep(k, maxl) rep(l, maxl) {
					dp[k][sl][l] = maxn;
				}				
			} else {
				rep(k, maxl) rep(l, maxl) {
					dp[k][l][sl] = maxn;
				}				
			}
			s[id].pop_back();
		}

		//cerr << s[0].size() << " " << s[1].size() << " " << s[2].size() << " " << dp[s[0].size()][s[1].size()][s[2].size()] << endl;

		puts(dp[s[0].size()][s[1].size()][s[2].size()] <= n ? "YES" : "NO");
	}

	return 0;
}