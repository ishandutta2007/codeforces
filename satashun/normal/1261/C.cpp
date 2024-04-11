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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	int n, m;
	cin >> n >> m;
	V<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}

	VV<int> ac(n + 1, V<int>(m + 1));
	rep(i, n) {
		rep(j, m) {
			ac[i+1][j+1] = ac[i][j+1] + ac[i+1][j] - ac[i][j] + (s[i][j] == 'X');
		}
	}

	VV<int> state(n, V<int>(m));

	auto ims = ac;
	int lo = 0, hi = 1010;

	while (hi - lo > 1) {
		int x = (lo + hi) / 2;

		rep(i, n + 1) rep(j, m + 1) ims[i][j] = 0;
		rep(i, n) rep(j, m) state[i][j] = 0;

		rep(i, n) {
			rep(j, m) {
				if (i >= x && i + x < n && j >= x && j + x < m) {
					int num = ac[i+x+1][j+x+1] - ac[i+x+1][j-x] - ac[i-x][j+x+1] + ac[i-x][j-x];
					if (num == (x * 2 + 1) * (x * 2 + 1)) {
						++ims[i+x+1][j+x+1];
						++ims[i-x][j-x];
						--ims[i+x+1][j-x];
						--ims[i-x][j+x+1];
						state[i][j] = 1;
					}
				}
			}
		}

		rep(i, n + 1) {
			rep(j, m) {
				ims[i][j+1] += ims[i][j];
			}
		}
		rep(j, m + 1) {
			rep(i, n) {
				ims[i+1][j] += ims[i][j];
			}
		}
		bool ok = 1;
		rep(i, n) rep(j, m) if (s[i][j] == 'X' && ims[i][j] == 0) {
			ok = 0;
		}
		if (ok) {
			lo = x;
		} else {
			hi = x;
		}
	}

	cout << lo << endl;
	{
		int x = lo;
		rep(i, n + 1) rep(j, m + 1) ims[i][j] = 0;
		rep(i, n) rep(j, m) state[i][j] = 0;

		rep(i, n) {
			rep(j, m) {
				if (i >= x && i + x < n && j >= x && j + x < m) {
					int num = ac[i+x+1][j+x+1] - ac[i+x+1][j-x] - ac[i-x][j+x+1] + ac[i-x][j-x];
					if (num == (x * 2 + 1) * (x * 2 + 1)) {
						state[i][j] = 1;
					}
				}
			}
		}
	}

	rep(i, n) {
		rep(j, m) {
			cout << (state[i][j] ? 'X' : '.');
		}
		cout << "\n";
	}

	return 0;
}