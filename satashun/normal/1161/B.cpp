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
	int n, m;
	cin >> n >> m;
	vector<pii> vec;
	set<pii> st;

	rep(i, m) {
		int l, r;
		cin >> l >> r; --l; --r;
		if (l > r) swap(l, r);
		vec.eb(l, r);
		st.insert(mp(l, r));
	}

	for (int k = 1; k < n; ++k) {
		if (n % k != 0) continue;
		bool ok = 1;
		for (auto &e : vec) {
			int a = (e.fi + k) % n;
			int b = (e.se + k) % n;
			if (a > b) swap(a, b);
			if (!st.count(mp(a, b))) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");

	return 0;
}