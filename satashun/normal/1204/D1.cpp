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

	string t;
	rep(i, n) {
		int c0 = 0, c1 = 0;
		bool f = 1;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == '0') {
				++c0;
			} else {
				++c1;
			}
			if (c0 > c1) {
				f = 0;
				break;
			}
		}
		if (f) {
			t.pb('0');
		} else {
			t.pb(s[i]);
		}
	}

	cout << t << endl;

	return 0;
}