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

const int L = TEN(9);

bool put(int x, int y) {
	printf("%d %d\n", x, y);
	fflush(stdout);
	string res; cin >> res;
	return res == "black";
}

int main() {
	int n; cin >> n;

	bool lc = put(0, L / 2);
	int lo = 0, hi = L;

	rep(i, n-1) {
		int m = (lo + hi) / 2;
		bool res = put(m, L / 2);

		if (res == lc) {
			lo = m;
		} else {
			hi = m;
		}
	}

	printf("%d %d %d %d\n", lo, L/2-1, hi, L/2+1);
	return 0;
}