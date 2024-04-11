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

int ask(V<int> a, V<int> b) {
	printf("%d %d", a.size(), b.size());
	for (int v : a) {
		printf(" %d", v + 1);
	}
	for (int v : b) {
		printf(" %d", v + 1);
	}
	puts("");
	fflush(stdout);
	int t;
	scanf("%d", &t);
	return t;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		int mx = -1;

		for (int i = 0; i < 9; ++i) {
			V<int> a, b;
			rep(j, n) {
				if ((j >> i) & 1) {
					a.pb(j);
				} else {
					b.pb(j);
				}
			}
			if (a.size() > 0 && b.size() > 0) {
				int d = ask(a, b);
				chmax(mx, d);
			}
		}
		printf("-1 %d\n", mx);
		fflush(stdout);
	}

	return 0;
}