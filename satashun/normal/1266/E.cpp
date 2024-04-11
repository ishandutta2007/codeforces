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

const int maxn = 200010;

map<int, int> T[maxn];

int main() {
	int n;
	scanf("%d", &n);
	V<int> a(n), b(n);
	ll sum = 0;

	rep(i, n) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	int q;
	scanf("%d", &q);

	while (q--) {
		int s, t, u;
		scanf("%d %d %d", &s, &t, &u);
		--s; --u;
		if (T[s].count(t)) {
			int v = T[s][t];
			T[s].erase(t);
			sum += min(a[v], b[v]);
			--b[v];
			sum -= min(a[v], b[v]);
		}

		if (u != -1) {
			T[s][t] = u;
			sum += min(a[u], b[u]);
			++b[u];
			sum -= min(a[u], b[u]);
		}
		printf("%lld\n", sum);
	}
	return 0;
}