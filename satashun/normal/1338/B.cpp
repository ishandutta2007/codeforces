#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
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

//n >= 3

const int maxn = 100010;

V<int> g[maxn];
int par[maxn];
bool f[2];

void dfs(int v, int p, int d) {
	par[v] = p;
	if (g[v].size() == 1) {
		f[d] = 1;
	}

	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v, d ^ 1);
		}
	}
}

int main() {
	int n; cin >> n;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}

	int r = -1;
	rep(i, n) if (g[i].size() != 1) {
		r = i;
		break;
	}

	dfs(r, -1, 0);

	set<int> st;

	int maxi = n - 1;

	rep(i, n) {
		if (g[i].size() == 1) {
			if (st.count(par[i])) {
				--maxi;
			} else {
				st.insert(par[i]);
			}
		}
	}

	int mini = -1;

	if (f[0] && f[1]) {
		mini = 3;
	} else {
		mini = 1;
	}

	cout << mini << " " << maxi << endl;

	return 0;
}