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
		/*
		string t(n * 2 - 1, '?');
		rep(i, n) {
			t[i * 2] = s[i];
		}
		dump(t);*/
		auto vec = manacher(s);
		dump(vec);

		int mx = 0, l = 1, r = 0;
		int lp = -1, rp = n;

		auto ok = [&](int p, int q) {
			//dump(t.substr(p * 2, q*2-p*2+1));
			//dump(vec[p + q]);
			//dump(q - p + 1);
			return vec[p + q] >= q - p + 1;
		};


		for (int i = 0; i * 2 <= n; ++i) {
			dump(i);
			if (i * 2 > mx) {
				mx = i * 2;
				l = r = i;
			}
				//left
			for (int j = lp + 1; j < rp; ++j) {
				if (ok(lp + 1, j)) {
					int nl = i + (j - lp) + i;
					if (nl > mx) {
						mx = nl;
						l = j + 1;
						r = i;
					}
				}
			}
				//right
			for (int j = rp - 1; j >= lp + 1; --j) {
				if (ok(j, rp - 1)) {
					int nl = i + (i + rp - j);
					if (nl > mx) {
						mx = nl;
						l = i;
						r = i + rp - j;
					}
				}
			}
			lp++;
			rp--;
			if (s[lp] != s[rp]) {
				break;
			}
		}

		string ans;
		rep(i, l) {
			ans.pb(s[i]);
		}
		rep(j, r) {
			ans.pb(s[n-r+j]);
		}
		cout << ans << "\n";
	}
	return 0;
}