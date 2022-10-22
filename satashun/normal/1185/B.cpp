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
	int n; cin >> n;
	while (n--) {
		string s, t;
		cin >> s >> t;
		int la = 0;
		bool ok = 1;

		rep(i, t.size()) {
			bool f = 0;
			if (i > 0 && la + 1 < s.size() && t[i] == s[la + 1]) {
				++la;
				f = 1;
			} else if (t[i] == s[la]) {
				f = 1;
			}
			if (!f) {
				ok = 0;
				break;
			}
		}
		puts(ok && la == (int)s.size()-1 ? "YES" : "NO");
	}
	return 0;
}