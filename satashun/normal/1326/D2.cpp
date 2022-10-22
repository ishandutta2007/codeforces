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

vector<int> manacher(const string &_s) {
	int n = _s.size();

	string s(n*2-1, '#');

	for (int i = 0; i < n; ++i) {
		s[i*2] = _s[i];
	}

	n = s.size();

	vector<int> rad(n);

	int i = 0, j = 0;

	while (i < n) {
		while (i-j >= 0 && i+j<n && s[i-j] == s[i+j]) ++j;
		rad[i] = j;

		int k = 1;
		while (i-k >= 0 && i+k < n && k+rad[i-k] < j) {
			rad[i+k] = rad[i-k];
			++k;
		}

		i += k;
		j -= k;
	}

	return rad;
}

int main() {
	int TC; cin >> TC;
	while (TC--) {
		string s;
		cin >> s;
		int n = s.size();
		auto vec = manacher(s);
		dump(vec);

		int mx = 0, li = 0, ri = 0;

		int com = 0;
		while (com * 2 <= n && s[com] == s[n-1-com]) {
			com++;
		}
		dump(com);

		if (com * 2 >= n) {
			cout << s << "\n";
			continue;
		}

		mx = com * 2;
		li = ri = com;

		for (int i = 0; i < vec.size(); ++i) {
			int r = vec[i];
			int lp = (i + 1 - r), rp = (i + r - 1);

			if (lp % 2 != 0) {
				++lp;
				--rp;
				if (lp > rp) {
					continue;
				}
			}		

			if (i < n && lp <= com * 2) {
				int nl = rp / 2 + 1;
				int nr = lp / 2;
				int nlen = nl + nr;
				if (nlen > mx) {
					mx = nlen;
					dump(mx);
					dump(mp(nl, nr));
					li = nl;
					ri = nr;
				}
			}
			if (i >= n && rp >= (n - 1 - com) * 2) {
				int nl = n - 1 - rp / 2;
				int nr = n - lp / 2;
				int nlen = nl + nr;
				if (nlen > mx) {
					mx = nlen;
					li = nl;
					ri = nr;
				}				
			}
		}
		dump(mx);
		dump(mp(li, ri));

		string ans;
		rep(i, li) {
			ans.pb(s[i]);
		}
		rep(j, ri) {
			ans.pb(s[n-ri+j]);
		}
		cout << ans << "\n";
	}
	return 0;
}