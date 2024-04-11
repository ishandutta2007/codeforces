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
	int n, m;
	scanf("%d %d", &n, &m);

	V<ll> in(n), out(n);

	rep(i, m) {
		int a, b;
		ll d;
		scanf("%d %d %lld", &a, &b, &d);
		--a; --b;
		out[a] += d;
		in[b] += d;
	}

	V<pair<ll, int>> ins, ous;

	rep(i, n) {
		if (in[i] > out[i]) {
			ins.eb(in[i] - out[i], i);
		} else if (in[i] < out[i]) {
			ous.eb(out[i] - in[i], i);
		}
	}

	V<pair<pii, ll>> ans;
	int now = 0;
	rep(i, ins.size()) {
		ll rem = ins[i].fi;
		int a = ins[i].se;
		while (rem > 0) {
			int b = ous[now].se;
			ll d = min(ous[now].fi, rem);
			rem -= d;
			ous[now].fi -= d;

			ans.eb(mp(b, a), d);
			if (ous[now].fi == 0) {
				++now;
			}
		}
	}

	int sz = ans.size();
	printf("%d\n", sz);
	rep(i, sz) {
		printf("%d %d %lld\n", ans[i].fi.fi + 1, ans[i].fi.se + 1, ans[i].se);
	}

	return 0;
}