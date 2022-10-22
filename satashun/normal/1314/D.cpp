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

const int maxn = 81;
const int maxk = 12;
const int M = TEN(9);

int n, k;
int d[maxn][maxn];
V<pii> vec[maxn][maxn];
int a[maxk];
int ans = TEN(9) + 10;
bool ng[maxn];

void check() {
	for (int i = 0; i <= k; i += 2) {
		ng[a[i]] = 1;
	}

	int cur = 0;
	for (int i = 1; i < k; i += 2) {
		int p = a[i-1], q = a[i+1];
		int d = M;
		for (auto &t : vec[p][q]) {
			if (!ng[t.se]) {
				d = t.fi;
				break;
			}
		}
		if (d == M) {
			for (int j = 0; j <= k; j += 2) {
				ng[a[j]] = 0;
			}	
			return ;
		}
		cur += d;
		if (cur > ans) {
			break;
		}
	}
	chmin(ans, cur);

	for (int i = 0; i <= k; i += 2) {
		ng[a[i]] = 0;
	}	
}

void dfs(int v) {
	if (v == k) {
		check();
		return ;
	}
	if (v == 0) {
		dfs(v + 2);
		return ;
	}
	rep(i, n) {
		a[v] = i;
		dfs(v + 2);
	}
}

int main() {
	cin >> n >> k;
	rep(i, n) {
		rep(j, n) {
			cin >> d[i][j];
		}
	}

	rep(i, n) {
		rep(j, n) {
			rep(k, n) {
				if (k != i && k != j) {
					vec[i][j].eb(mp(d[i][k] + d[k][j], k));
				}
			}
			sort(ALL(vec[i][j]));
		}
	}
	dfs(0);
	cout << ans << endl;

	return 0;
}