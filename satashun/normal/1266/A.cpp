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
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;

		int k = s.size();

		V<int> cnt(10);
		int sum = 0;
		rep(i, s.size()) {
			int x = s[i]-'0';
			++cnt[x];
			sum += x;
		}

		bool f = 0;

		if (cnt[0] == k) f = 1;

		if (cnt[0] > 0 && sum % 3 == 0) {
			--cnt[0];
			bool ev = 0;
			for (int i = 0; i < 10;i += 2) {
				if (cnt[i] > 0) {
					ev = 1;
				}
			}
			if (ev) {
				f = 1;
			}
		}
		puts(f ? "red" : "cyan");

	}
	return 0;
}