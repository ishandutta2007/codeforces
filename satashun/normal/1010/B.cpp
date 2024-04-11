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

int ask(int x) {
	printf("%d\n", x);
	fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

bool f[30];

int main() {
	int m, n; cin >> m >> n;

	rep(i, n) {
		int r = ask(1);
		if (r == 0) {
			return 0;
		}
		f[i] = (r == 1);
	}

	int lo = 1, hi = m + 1;
	rep(i, 60-n) {
		int x = (lo + hi) / 2;
		int r = ask(x);
		if (r == 0) {
			return 0;
		}
		if (!f[i % n]) r = -r;
		if (r > 0) {
			lo = x;
		} else {
			hi = x;
		}
	}

	return 0;
}