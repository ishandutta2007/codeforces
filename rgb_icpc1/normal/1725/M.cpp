#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int((x).size()))
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define F1(x) function<void(int)> x = [&] 
#define F2(x) function<void(int, int)> x = [&] 
#define F3(x) function<void(int, int, int)> x = [&]
 
template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
using LL = long long;
using PI = pair<int, int>;
using VI = vector<int>;
using VPI = vector<PI>;
const int N = 1000005;
const LL oo = 1000000000000000005LL;
const int P1 = 998244353;
const int P2 = 1000000007;
const int P = P1;

//assume -1 < x, y < P
inline int add(int x, int y) {
	return (x + y) % P;
}

inline int mul(int x, int y) {
	return 1LL * x * y % P;
}

inline int sub(int x, int y) {
	return (x + P - y) % P;
}

string itos(int x) {
	string str = "";
	while (x) {
		str += (x % 10 + '0');
		x /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

struct Pos {
	int u, f;
	LL d;
	Pos() {}
	Pos(int u, LL d, int f) : u(u), d(d), f(f) {}
};

bool operator<(const Pos& s1, const Pos& s2) {
	return s1.d > s2.d;
}

const int MN = N;
const int MM = N;
const LL INF = oo;

int n, m;
int a[MM], b[MM];
LL c[MM];
int fst[MN], nxt[MM];
LL d[MN][2], p[MN];
priority_queue<Pos> q;
vector<pair<int, LL>> con[N], rcon[N];

void init() {
	for (int i = 0; i < n; i ++) d[i][0] = d[i][1] = INF;
}

void Dijkstra(int s) {
	int e, u, v, w;
	Pos tp;
	init();
	d[s][0] = 0;
	q.push(Pos(s, 0, 0));
	while (!q.empty()) {
		tp = q.top();
		q.pop();
		u = tp.u;
		int f = tp.f;
		if (tp.d > d[u][f]) continue;
		if (f == 0) {
			for (auto e : con[u]) {
				v = e.fi, w = e.se;
				if (d[v][0] <= d[u][0] + w) continue;
				d[v][0] = d[u][0] + w;
				q.push(Pos(v, d[v][0], 0));
			}
			for (auto e : rcon[u]) {
				v = e.fi, w = e.se;
				if (d[v][1] <= d[u][0] + w) continue;
				d[v][1] = d[u][0] + w;
				q.push(Pos(v, d[v][1], 1));
			}
		} else {
			for (auto e : rcon[u]) {
				v = e.fi, w = e.se;
				if (d[v][1] <= d[u][1] + w) continue;
				d[v][1] = d[u][1] + w;
				q.push(Pos(v, d[v][1], 1));
			}
		}
	}
}

LL rlt[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int s = 0;
	for (int i = 0; i < m; i ++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i] --, b[i] --;
		con[a[i]].pb({b[i], c[i]});
		rcon[b[i]].pb({a[i], c[i]});
	}
	Dijkstra(s);
	for (int i = 1; i < n; i ++) {
		rlt[i] = min(d[i][0], d[i][1]);
		if (rlt[i] == INF) rlt[i] = -1;
	}
	for (int i = 1; i < n; i ++) cout << rlt[i] << " \n"[i == n - 1];
	return 0;
}