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

int e[110][110];
int mem[110][110][30];

bool dp(int v, int o, int la) {
	if (mem[v][o][la] != -1) {
		return mem[v][o][la];
	}
	int &t = mem[v][o][la];
	t = 0;
	rep(i, 110) if (e[v][i] >= la) {
		if (!dp(o, i, e[v][i])) {
			t = 1;
		}
	}
	return t;
}

int main() {
	memset(mem, -1, sizeof(mem));
	memset(e, -1, sizeof(e));

	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int u, v; char c;
		cin >> u >> v >> c;
		--u; --v;
		e[u][v] = c - 'a';
	}

	rep(i, n) {
		rep(j, n) {
			printf("%c", dp(i, j, 0) ? 'A' : 'B');
		}
		puts("");
	}


	return 0;
}