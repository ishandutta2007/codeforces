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

const int maxn = 200010;

int n;
vi g[maxn];
ll sz[maxn];
ll num[2][maxn];
ll sum, ad;

void dfs(int v, int p) {
	num[0][v] = 1;
	sz[v] = 1;

	for (int to : g[v]) if (to != p) {
		dfs(to, v);
		sz[v] += sz[to];
		sum += sz[to] * (n - sz[to]);
		ad += num[0][v] * num[0][to] + num[1][v] * num[1][to];
		num[0][v] += num[1][to];
		num[1][v] += num[0][to];
	}
}

int main() {
	scanf("%d", &n);
	rep(i, n-1) {
		int a, b;
		scanf("%d %d", &a, &b); --a; --b;
		g[a].pb(b); g[b].pb(a);
	}
	dfs(0, -1);
	ll ans = (sum + ad) / 2;
	cout << ans << endl;

	return 0;
}