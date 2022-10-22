#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

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

	int n = s.size();

	vi h(n+1);
	h[0] = 0;
	rep(i, n) {
		h[i+1] = h[i] + (s[i] == '0' ? 1 : -1);
	}

	vi can(n);

	string t;

	set<int> ss;
	for (int i = n-1; i >= 0; --i) {
		auto it = ss.upper_bound(h[i+1]);
		if (it != ss.end()) {
			can[i] = 0;
		} else {
			can[i] = 1;
		}
		ss.insert(h[i+1]);
	}

	rep(i, n) {
		if (can[i]) {
			t.pb('0');
		} else {
			t.pb(s[i]);
		}
	}

	cout << t << endl;

	return 0;
}