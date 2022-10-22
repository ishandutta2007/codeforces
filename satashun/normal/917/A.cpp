#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
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

const int maxn = 5010;

int tor[maxn], tol[maxn];

int main() {
	string s; cin >> s;
	int n = s.size();
	dump(s);

	rep(i, n) {
		tor[i] = n;
		int cur = 0;
		for (int j = i; j < n; ++j) {
			if (s[j] == ')') {
				--cur;
			} else {
				++cur;
			}
			if (cur < 0) {
				tor[i] = j;
				break;
			}
		}
		dump(mp(tor[i], cur));
	}

	rep(j, n) {
		tol[j] = -1;
		int cur = 0;
		for (int i = j; i >= 0; --i) {
			if (s[i] == '(') {
				--cur;
			} else {
				++cur;
			}
			if (cur < 0) {
				tol[j] = i;
				break;
			}
		}
		dump(mp(tol[j], cur));
	}

	int ans = 0;
	rep(i, n) {
		for (int j = i + 1; j < n; j += 2) {
			if (tor[i] > j && tol[j] < i) {
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}