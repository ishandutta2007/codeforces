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

int a[510][510];

int main() {
	int r, c; cin >> r >> c;

	if (r == 1 && c == 1) {
		puts("0");
		return 0;
	}

	if (c != 1) {
		rep(i, r) {
			rep(j, c) {
				a[i][j] = (i + 1) * (r + j + 1);
			}
		}
	} else {
		rep(i, r) {
			a[i][0] = i + 2;
		}
	}

	rep(i, r) {
		rep(j, c) {
			printf("%d%c", a[i][j], j == c - 1 ? '\n' : ' ');
		}
	}

	return 0;
}