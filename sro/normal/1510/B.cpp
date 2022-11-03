#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
 
struct Edge {
	int to, cap, rev, cost;
	Edge(int to, int cap, int rev, int cost): to(to), cap(cap), rev(rev), cost(cost) {}
};
 
struct Mincostflow {
	vector<Edge> egs[2160];
	int inline addedge(int u, int v, int cap, int cost) {
		egs[u].emb(v, cap, SZ(egs[v]), cost);
		egs[v].emb(u, 0, SZ(egs[u]) - 1, -cost);
		return SZ(egs[u]) - 1;
	}
	int dis[2160];
	bool inq[2160];
	int prv[2160], pre[2160];
	bool inline spfa(int s, int t) {
		memset(dis, Inf, sizeof(dis));
		deque<int> q;
		q.pub(s); dis[s] = 0;
		while (SZ(q)) {
			int x = q.front(); q.pop_front();
			inq[x] = 0;
			loop(i, SZ(egs[x])) {
				Edge &e = egs[x][i];
				if (e.cap && dis[e.to] > dis[x] + e.cost) {
					dis[e.to] = dis[x] + e.cost;
					prv[e.to] = x; pre[e.to] = i;
					if (!inq[e.to]) {
						inq[e.to] = 1;
						if (SZ(q) && dis[e.to] < dis[q.front()]) q.push_front(e.to);
						else q.pub(e.to);
					}
				}
			}
		}
		return dis[t] < 0;
	}
	int inline mcmf(int s, int t) {
		int ans = 0;
		while (spfa(s, t)) {
			int fl = Inf;
			for (int i = t; i != s; i = prv[i]) {
				fl = min(fl, egs[prv[i]][pre[i]].cap);
			}
			ans += fl * dis[t];
			cerr<<fl<<endl;
			for (int i = t; i != s; i = prv[i]) {
				Edge &e = egs[prv[i]][pre[i]];
				e.cap -= fl;
				egs[i][e.rev].cap += fl;
			}
		}
		return ans;
	}
} nf;
 
const int S = 0, T = 2159;
int d, n;
bitset<10> bs[1080];
int eg[1080][1080];
int nxt[1080], lgl[1080];
 
int inline id(int i, int j) {
	return i * 2 + j - 1;
}
 
int main() {
	scanf("%d%d", &d, &n);
	cont(i, n) {
		string s; cin >> s;
		reverse(all(s));
		bs[i] = bitset<10>(s);
		nf.addedge(id(i, 0), id(i, 1), 1, -1e6);
	}
	memset(eg, -1, sizeof(eg));
	cont(i, n) cont(j, n) if (i != j && (bs[i] & bs[j]).count() == bs[i].count()) {
		eg[i][j] = nf.addedge(id(i, 1), id(j, 0), 1, 0);
	}
	cont(i, n) nf.addedge(id(i, 1), T, 1, bs[i].count() + 1);
	cont(i, n) nf.addedge(S, id(i, 0), 1, 0);
	nf.mcmf(S, T);
	cont(i, n) cont(j, n) if (~eg[i][j] && !nf.egs[id(i, 1)][eg[i][j]].cap) nxt[i] = j, lgl[j] = 1;
	vector<int> ans;
	cont(i, n) if (!lgl[i]) {
		if (SZ(ans)) ans.pub(-1);
		bitset<10> stt;
		for (int j = i; j; j = nxt[j]) {
			bitset<10> xju = bs[j] ^ stt;
			while (xju.count()) {
				int pos = xju._Find_first();
				ans.pub(pos);
				xju[pos] = 0;
			}
			stt = bs[j];
		}
	}
	printf("%d\n", SZ(ans));
	parse(i, ans) {
		if (~i) printf("%d ", i);
		else printf("R ");
	}
	return 0;
}