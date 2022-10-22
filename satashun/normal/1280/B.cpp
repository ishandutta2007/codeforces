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

const int maxn = 70;
string s[maxn];
bool f[maxn][maxn];

int main() {
	int TC; cin >> TC;
	while (TC--) {
		int r, c;
		cin >> r >> c;
		rep(i, r) {
			cin >> s[i];
			rep(j, c) {
				f[i][j] = (s[i][j] == 'A');
			}
		}

		set<int> st;
		rep(i, r) {
			rep(j, c) st.insert(f[i][j]);
		}
		if (st.size() == 1) {
			if (*st.begin() == 1) {
				puts("0");
			} else {
				puts("MORTAL");
			}
			continue;
		}

		bool one = 0;
		{
			bool ok = 1;
			rep(i, r) if (!f[i][0]) {
				ok = 0;
			}
			one |= ok;
		}
		{
			bool ok = 1;
			rep(j, c) if (!f[0][j]) {
				ok = 0;
			}
			one |= ok;
		}		
		{
			bool ok = 1;
			rep(i, r) if (!f[i][c-1]) {
				ok = 0;
			}
			one |= ok;
		}
		{
			bool ok = 1;
			rep(j, c) if (!f[r-1][j]) {
				ok = 0;
			}
			one |= ok;
		}		
		if (one) {
			puts("1");
		} else if (f[0][0] || f[r-1][0] || f[r-1][c-1] || f[0][c-1]) {
			puts("2");
		} else {
			bool two = 0;
			{
				rep(i, r) {
					bool ok = 1;
					rep(j, c) if (!f[i][j]) {
						ok = 0;
					}
					two |= ok;
				}
				rep(j, c) {
					bool ok = 1;
					rep(i, r) if (!f[i][j]) {
						ok = 0;
					}
					two |= ok;
				}
			}
			if (two) {
				puts("2");
			} else {
				bool t=0;
				rep(i, r) {
					rep(j, c) {
						if (f[i][j] && (i == 0 || j == 0 || i == r-1 || j == c-1)) {
							puts("3");
							t=1;
							i=r;j=c;
							break;
						}
					}
				}
				if (!t) {
					puts("4");
				}
			}
		}
	}
	return 0;
}