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

const int maxc = 30;
const int INF = 1e9;
const int S = 2010;

int mx[maxc], Mx[maxc], my[maxc], My[maxc];
int cnt[S][S], ac[S][S];

int main() {
	int TC; cin >> TC;
	while (TC--) {
		rep(i, maxc) {
			mx[i] = my[i] = INF;
			Mx[i] = My[i] = -1;
		}

		int n, m;
		cin >> n >> m;

		vector<string> s(n);

		rep(i, n) {
			cin >> s[i];
			rep(j, m) {
				if (s[i][j] != '.') {
					int c = s[i][j] - 'a';
					mx[c] = min(mx[c], i);
					my[c] = min(my[c], j);
					Mx[c] = max(Mx[c], i);
					My[c] = max(My[c], j);					
				}
			}
		}

		int t = -1;
		for (int i = maxc - 1; i >= 0; --i) {
			if (mx[i] != INF) {
				t = i;
				break;
			}
		}

		if (t == -1) {
			puts("YES");
			puts("0");
			continue;
		}

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				cnt[i][j] = 0;
				ac[i][j] = 0;
			}
		}

		bool ok = 1;
		vector<pair<pii, pii> > vec(maxc);

		for (int col = t; col >= 0; --col) {
			rep(i, n) rep(j, m) if (s[i][j] == 'a' + col) {
				++cnt[i][j];
			}
			rep(i, n) rep(j, m) {
				ac[i+1][j+1] = ac[i][j+1] + ac[i+1][j] - ac[i][j] + cnt[i][j];
			}
			if (mx[col] != INF) {
				int a = mx[col], b = my[col], c = Mx[col], d = My[col];
				if (ac[c+1][d+1] - ac[c+1][b] - ac[a][d+1] + ac[a][b] == (c-a+1) * (d-b+1) && min(c-a, d-b) == 0) {
					vec[col] = mp(mp(a, b), mp(c, d));
				} else {
					ok = false;
				}
			}
		}

		if (!ok) {
			puts("NO");
		} else {
			puts("YES");
			printf("%d\n", t + 1);
			for (int i = 0; i <= t; ++i) {
				auto ans = vec[i];
				if (mx[i] == INF) {
					for (int j = i + 1; j <= t; ++j) {
						if (mx[j] != INF) {
							ans = vec[j];
							break;
						}
					}
				}
				printf("%d %d %d %d\n", ans.fi.fi + 1, ans.fi.se + 1, ans.se.fi + 1, ans.se.se + 1);
			}
		}
	}
	return 0;
}