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

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

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

bool e[26][26];
int deg[26];
bool use[26];

int main() {
	int TC; cin >> TC;
	while (TC--) {
		string s; cin >> s;
		memset(e, 0, sizeof(e));
		memset(deg, 0, sizeof(deg));
		int n = s.size();
		rep(i, n-1) {
			int a = s[i] - 'a', b = s[i+1] - 'a';
			e[a][b] = e[b][a] = 1;
			//dump(mp(a,b));
		}
		bool ok = 1;
		rep(i, 26) {
			rep(j, 26) {
				if (e[i][j]) {
					deg[i]++;
				}
			}
			//dump(deg[i]);
			if (deg[i] > 2) {
				ok = 0;
				break;
			}
		}

		memset(use, 0, sizeof(use));
		string ans;
		rep(i, 26) if (deg[i] == 1 && !use[i]) {
			dump(i);
			int v = i;
			while (true) {
				ans.pb('a' + v);
				use[v] = 1;
				int nx = -1;
				rep(j, 26) if (e[v][j] && !use[j]) {
					nx = j;
					break;
				}
				if (nx == -1) {
					break;
				}
				v = nx;
			}
		}

		rep(i, 26) {
			if (deg[i] && !use[i]) {
				ok = 0;
			}
			if (!use[i]) {
				ans.pb('a' + i);
			}
		}

		if (!ok) {
			puts("NO");
		} else {
			puts("YES");
			cout << ans << endl;
		}

	}
	return 0;
}