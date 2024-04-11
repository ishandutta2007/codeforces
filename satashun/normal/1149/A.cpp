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
	int c[3] = {};
	rep(i, n) {
		int x; cin >> x;
		++c[x];
	}

	if (c[2] == 0) {
		rep(i, n) printf("1%c", i == n-1 ? '\n' : ' ');
		return 0;
	}

	vi ans;
	ans.pb(2); --c[2];

	if (c[1] != 0) {
		--c[1];
		ans.pb(1);
	}

	while (c[1] + c[2] > 0) {
		if (c[2] > 0) {
			ans.pb(2);
			--c[2];
		} else if (c[1] > 0) {
			ans.pb(1);
			--c[1];
		}
	}
	rep(i, n) printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');

	return 0;
}