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

const int maxn = 1000010;

int tp[maxn];
bool val[maxn];
int ch[maxn][2];
bool flip[maxn];

bool eval(int v) {
	if (tp[v] == -1) {
		return val[v];
	} else if (tp[v] == 2) {
		return val[v] = !eval(ch[v][0]);
	} else if (tp[v] == 0) {
		return val[v] = (eval(ch[v][0]) & eval(ch[v][1]));
	} else if (tp[v] == 1) {
		return val[v] = (eval(ch[v][0]) | eval(ch[v][1]));
	} else {
		return val[v] = (eval(ch[v][0]) ^ eval(ch[v][1]));
	}
}

void solve(int v) {
	dump(v);dump(tp[v]);
	if (tp[v] == -1) {
		flip[v] = 1;
	} else if (tp[v] == 2) {
		solve(ch[v][0]);
	} else if (tp[v] == 0) {
		if (val[ch[v][0]] && val[ch[v][1]]) {
			solve(ch[v][0]);
			solve(ch[v][1]);
		} else if (val[ch[v][0]] && !val[ch[v][1]]) {
			solve(ch[v][1]);
		} else if (!val[ch[v][0]] && val[ch[v][1]]) {
			solve(ch[v][0]);
		}
	} else if (tp[v] == 1) {
		if (!val[ch[v][0]] && !val[ch[v][1]]) {
			solve(ch[v][0]);
			solve(ch[v][1]);
		} else if (val[ch[v][0]] && !val[ch[v][1]]) {
			solve(ch[v][0]);
		} else if (!val[ch[v][0]] && val[ch[v][1]]) {
			solve(ch[v][1]);
		}
	} else {
		solve(ch[v][0]);
		solve(ch[v][1]);
	}
}

int main() {
	int n; scanf("%d", &n);
	memset(ch, -1, sizeof(ch));
	memset(tp, -1, sizeof(tp));

	rep(i, n) {
		char in[5];
		scanf("%s", in);
		string op = in;
		if (op == "AND") {
			tp[i] = 0;
			int x, y; scanf("%d %d", &x, &y);
			--x; --y;
			ch[i][0] = x, ch[i][1] = y;
		} else if (op == "OR") {
			tp[i] = 1;
			int x, y; scanf("%d %d", &x, &y);
			--x; --y;
			ch[i][0] = x, ch[i][1] = y;			
		} else if (op == "IN") {
			int f; scanf("%d", &f);
			scanf("%d", &f);
			val[i] = f;
		} else if (op == "NOT") {
			tp[i] = 2;
			int x; scanf("%d", &x); --x;
			ch[i][0] = x;
		} else if (op == "XOR") {
			tp[i] = 3;
			int x, y; scanf("%d %d", &x, &y);
			--x; --y;
			ch[i][0] = x, ch[i][1] = y;		
		} else {
			//assert(false);
		}
	}

	rep(i, n) {
		dump(val[i]);
	}

	eval(0);
	solve(0);
	string ans;

	rep(i, n) if (tp[i] == -1) {
		ans.pb((flip[i]^val[0]) ? '1' : '0');
	}
	cout << ans << endl;

	return 0;
}