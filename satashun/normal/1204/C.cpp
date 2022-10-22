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

const int maxn = 110;
const int INF = 1e9;
int d[maxn][maxn];

int main() {
	int n; cin >> n;
	rep(i, n) rep(j, n) d[i][j] = INF;
	rep(i, n) d[i][i] = 0;

	rep(i, n) {
		string s;
		cin >> s;
		rep(j, n) if (s[j] == '1') {
			d[i][j] = 1;
		} 
	}

	rep(k, n) rep(i, n) rep(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int m; cin >> m;
	vi p(m);

	rep(i, m) {
		cin >> p[i];
		--p[i];
	}

	vi dp(m, INF), la(n, -1), pre(m, -1);

	rep(i, m) {
		if (i == 0) {
			dp[i] = 1;
		}

		rep(j, n) {
			if (la[j] != -1 && i - la[j] == d[j][p[i]]) {
				if (dp[i] > dp[la[j]] + 1) { 
					dp[i] = dp[la[j]] + 1;
					pre[i] = la[j]; 
				}
			}
		}

		la[p[i]] = i;
	}

	vi vs;
	int c = m-1;
	while (c != -1) {
		vs.pb(p[c] + 1);
		c = pre[c];
	}
	reverse(ALL(vs));

	printf("%d\n", vs.size());
	rep(i, vs.size()) printf("%d%c", vs[i], i+1 == vs.size() ? '\n' : ' ');

	return 0;
}