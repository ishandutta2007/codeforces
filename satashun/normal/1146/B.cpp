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

int main() {
	string s;
	cin >> s;
	string t;
	for (char c : s) if (c != 'a') {
		t.pb(c);
	}

	int n = t.size();

	bool ok = 1;

	if (n % 2 == 1) {
		ok = 0;
	} else {
		rep(i, n/2) {
			if (t[i] != t[i+n/2]) {
				ok = 0;
			}
		}
	}

	if (ok) {
		for (int i = (int)s.size()-1, k = 0; i >= 0 && k < n/2; --i, ++k) {
			if (s[i] == 'a') {
				ok = 0;
			}
		}
	}

	if (!ok) {
		puts(":(");
	} else {
		cout << s.substr(0, s.size() - n/2) << endl;
	}
	return 0;
}