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
#define dump(x) cout << #x << " = " << (x) << endl
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

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		V<pii> ans;
		rep(i, n/2) {
			if (s[i] == ')') {
				int r = i;
				for (; r < n && s[r] == ')';) {
					++r;
				}
				ans.eb(i, r);
				reverse(s.begin() + i, s.begin() + r + 1);
			}
		}
		rep(i, k-1) {
			ans.eb(i * 2 + 1, n / 2 + i);
			//reverse(s.begin() + i * 2 + 1, s.begin() + n / 2 + i + 1);
		}

		printf("%d\n", ans.size());
		for (auto p : ans) {
			printf("%d %d\n", p.fi + 1, p.se + 1);
		}
	}
	return 0;
}