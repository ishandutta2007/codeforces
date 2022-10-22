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
#define dump(x) cout << #x << " = " << (x) << endl
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

const ll MOD = TEN(9) + 7;
const int maxn = 150000;

char in[10];

int main() {
	int q; scanf("%d", &q);
	set<int> st;
	set<int> sl, sr; //alive
	ll ans = 1;

	rep(i, q) {
		int p;
		scanf("%s %d", in, &p);
		string s = in;

		if (s == "ACCEPT") {
			st.erase(p);
			if (!sl.count(p) && !sr.count(p)) {
				ans = ans * 2 % MOD;
			}
			sl.erase(p);
			sr.erase(p);
			if (sl.size() && *sl.rbegin() > p) {
				puts("0");
				return 0;				
			}
			if (sr.size() && *sr.begin() < p) {
				puts("0");
				return 0;				
			}
			for (auto &x : st) {
				if (x < p) {
					sl.insert(x);
				} else {
					sr.insert(x);
				}
			}
			st.clear();
		} else {
			if ((sl.size() && *sl.rbegin() > p) && (sr.size() && *sr.begin() < p)) {
				puts("0");
				return 0;
			}
			if (sl.size() && *sl.rbegin() > p) {
				sl.insert(p);
			} else if (sr.size() && *sr.begin() < p) {
				sr.insert(p);
			} else {
				st.insert(p);
			}
		}
	}
	cout << ans * (st.size() + 1) % MOD << endl;

	return 0;
}