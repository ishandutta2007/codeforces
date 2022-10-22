#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cerr << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

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

const int maxn = 160000;
const string C = "?onetw";

int dp[maxn][36];
int pre[maxn][36];

int main() {
	int TC; cin >> TC;
	while (TC--) {
		string s; cin >> s;
		int n = s.size();
		rep(i, n+1) {
			rep(j, 36) {
				dp[i][j] = pre[i][j] = -1;
			}
		}

		dp[0][0] = 0;

		rep(i, n) {
			int p = 0;
			rep(j, 6) if (C[j] == s[i]) {
				p = j;
			}
			rep(j, 36) if (dp[i][j] != -1) {
				if (dp[i+1][j] < dp[i][j]) {
					dp[i+1][j] = dp[i][j];
					pre[i+1][j] = j;
				}
				if (j == 8 && p == 3) continue;
				if (j == 29 && p == 1) continue;
				int nj = j % 6 * 6 + p;
				if (dp[i+1][nj] < dp[i][j] + 1) {
					dp[i+1][nj] = dp[i][j] + 1;
					pre[i+1][nj] = j;
				}
			}
		}

		int mx = -1, p = -1;
		rep(j, 36) {
			if (mx < dp[n][j]) {
				mx = dp[n][j];
				p = j;
			}
		}
		V<int> us(n);
		V<int> vec;
		for (int i = n; i >= 1; --i) {
			vec.pb(dp[i][p]);
			p = pre[i][p];
		}
		vec.pb(0);
		reverse(ALL(vec));
		rep(i, n) if (vec[i] != vec[i+1]) {
			us[i] = 1;
		}

		int cnt = 0;
		rep(i, n) if (!us[i]) ++cnt;
		printf("%d\n", cnt);
		bool f = 1;
		rep(i, n) if (!us[i]) {
			if (!f) {
				printf(" ");
			}
			printf("%d", i + 1);
			f = 0;
		}
		puts("");
	}
	return 0;
}