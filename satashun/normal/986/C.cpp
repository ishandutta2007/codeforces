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

const int maxn = 1 << 22;

int n, m;
int a[maxn];
bool vis[maxn * 2];
vi vec[maxn];

void dfs(int v) {
	vis[v] = true;

	if (v < (1<<n)) {
		rep(i, n) {
			if ((v >> i) & 1) {
				int nx = v ^ (1 << i);
				if (!vis[nx]) dfs(nx);
			}
		}
		for (int id : vec[v]) {
			if (!vis[(1<<n)+id]) {
				dfs((1<<n)+id);
			}
		}

	} else {
		int id = v - (1<<n);
		if (!vis[(1<<n)-1-a[id]]) {
			dfs((1<<n)-1-a[id]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	rep(i, m) {
		scanf("%d", &a[i]);
		vec[a[i]].pb(i);
	}

	int now = 0;
	rep(i, m) {
		if (!vis[(1<<n)+i]) {
			dfs((1<<n)+i);
			now++;
		}
	}

	cout << now << endl;

	return 0;
}