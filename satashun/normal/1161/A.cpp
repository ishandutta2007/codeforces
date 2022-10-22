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

const int maxn = 100010;
set<int> s[maxn];

int main() {
	int n, k; cin >> n >> k;
	int ans = 0;

	vi x(k);
	rep(i, k) {
		cin >> x[i]; --x[i];
		s[x[i]].insert(i);
	}

	rep(p, n) {
		int i = k;

		if (!s[p].size()) {
			++ans;
		} else {
			i = *s[p].begin() + 1;
		}

		for (int q : {p-1, p+1}) {
			if (q < 0 || q >= n) continue;
			auto it = s[q].lower_bound(i);
			if (it == s[q].end()) {
				++ans;
			}
		}
	}

	cout << ans << endl;

	return 0;
}