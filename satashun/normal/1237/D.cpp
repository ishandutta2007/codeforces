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

int main() {
	int n; cin >> n;
	V<int> a(n); rep(i, n) cin >> a[i];

	{
		int m = *min_element(ALL(a));
		int M = *max_element(ALL(a));
		if (m * 2 >= M) {
			rep(i, n) printf("-1%c", i == n-1 ? '\n' : ' ');
			return 0;
		}
	}

	rep(i, n) a.pb(a[i]);
	rep(i, n) a.pb(a[i]);

	int N = n * 3;
	V<pii> vec(N);
	rep(i, N) vec[i] = mp(a[i], i);
	sort(ALL(vec));
	reverse(ALL(vec));

	int now = 0;
	const int INF = 1e9;

	set<int> st;
	V<int> tor(N + 1, INF);

	rep(i, N) {
		int x = vec[i].fi;
		while (now < N && vec[now].fi > x * 2) {
			st.insert(vec[now].se);
			now++;
		}
		auto it = st.lower_bound(vec[i].se);
		if (it != st.begin()) {
			--it;
			chmin(tor[*it], vec[i].se);
		}
	}

	for (int i = N-1; i >= 0; --i) {
		chmin(tor[i], tor[i+1]);
	}

	V<int> ans(n, INF);

	rep(i, n) {
		chmin(ans[i], tor[i] - i);
		chmin(ans[i], tor[i+n] - i - n);
		chmin(ans[i], tor[i+n+n] - i - n - n);
	}

	rep(i, n) printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');

	return 0;
}