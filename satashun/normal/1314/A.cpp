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

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

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
	V<int> a(n); rep(i, n) cin >> a[i];
	V<int> t(n); rep(i, n) cin >> t[i];

	V<pii> ev(n);
	rep(i, n) {
		ev[i] = mp(a[i], i);
	}
	sort(ALL(ev));

	V<int> b = a;
	sort(ALL(b));
	rep(i, n) b[i] -= i;
	for (int i = 1; i < n; ++i) {
		b[i] = max(b[i-1], b[i]);
	}
	rep(i, n) b[i] += i;
	dump(b);

	ll ans = 0;
	int now = 0;
	multiset<int> st;
	ll sum = 0;

	int la = -1;

	for (int tm : b) {
		ans += sum * (tm - la);
		while (now < n && ev[now].fi <= tm) {
			int id = ev[now].se;
			st.insert(t[id]);
			sum += t[id];
			now++;
		}
		auto it = --st.end();
		sum -= *it;
		st.erase(it);
		la = tm;
	}
	cout << ans << endl;

	return 0;
}