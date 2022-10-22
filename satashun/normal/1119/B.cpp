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
	int n, h;
	cin >> n >> h;
	vi a(n); rep(i, n) cin >> a[i];

	int ans = 0;
	rep(i, n) {
		priority_queue<int> que;

		for (int j = 0; j <= i; ++j) {
			que.push(a[j]);
		}

		bool ok = 1;

		int c = 0;
		while (!que.empty()) {
			int t = que.top(); que.pop();
			c += t;
			if (c > h) {
				ok = 0;
				break;
			}
			if (que.size()) que.pop();
 		}
 		if (ok) {
 			ans = i + 1;
 		}
	}
	cout << ans << endl;

	return 0;
}