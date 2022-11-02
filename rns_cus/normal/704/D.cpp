#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 1000100

template<class T> inline void chkmin(T &a, T b){ if(a > b) a = b; }

class maxFlow_with_demond{ ///dinic_maxflow with lower bounds and capacity
public:
#define MN 1000010

	int head[MN], nxt[MN], to[MN], nodes, cnt, cap[MN];
	int demond[MN], q[MN], src, dst, dist[MN], nowi[MN];
	const LL LL_INF = 1e18;

	void init(){ cnt = 2; }

	inline void insert_Edge(int _from, int _to, int _cap){
		to[cnt] = _to, cap[cnt] = _cap, nxt[cnt] = head[_from], head[_from] = cnt ++;
		to[cnt] = _from, cap[cnt] = 0, nxt[cnt] = head[_to], head[_to] = cnt ++;
	}

	inline void add_Edge(int _from, int _to, int _low, int _cap){
		insert_Edge(_from, _to, _cap - _low);
		demond[_from] -= _low;
		demond[_to] += _low;
	}

	inline bool dinic_bfs(){
		fill(dist, dist + nodes, -1);
		int qt = 0;
		dist[src] = 0, q[qt ++] = src;
		for(int qh = 0; qh < qt; qh ++){ int u = q[qh];
			for(int id = head[u]; id; id = nxt[id]) if(cap[id]) { int v = to[id];
				if(dist[v] == -1){ dist[v] = dist[u] + 1, q[qt ++] = v; }
			}
		} return dist[dst] >= 0;
	}

	inline LL dinic_dfs(int u, LL f){
		if(u == dst) return f;
		LL ret = 0;
		for(int &id = nowi[u]; id; id = nxt[id]) if(cap[id]) { int v = to[id];
			if(dist[v] == dist[u] + 1){
				LL tmp = dinic_dfs(v, min(f, (LL)cap[id]));
				f -= tmp, ret += tmp, cap[id] -= tmp, cap[id^1] += tmp;
				if(!f) return ret;
			}
		} return ret;
	}

	LL dinic_MaxFlow(int _src, int _dst){
		LL flow = 0;
		src = _src, dst = _dst;
		while(dinic_bfs()){
			for(int i = 0; i <= nodes; i ++) nowi[i] = head[i];
			flow += dinic_dfs(src, LL_INF);
		} return flow;
	}

	LL MaxFlow(int S, int T, int _nodes){
		nodes = _nodes + 1;
		int SS = nodes ++, TT = nodes ++;
		LL TOT = 0;
		for(int i = 1; i < nodes; i ++) {
			if(demond[i] > 0) TOT += demond[i], insert_Edge(SS, i, demond[i]);
			else if(demond[i] < 0) insert_Edge(i, TT, -demond[i]);
		}

		insert_Edge(T, S, 1e9);
		if(TOT != dinic_MaxFlow(SS, TT)) return -1;
		return dinic_MaxFlow(S, T);
	}
} Graph;

unordered_map <int, int> mp;
int cur;
int get_id(int x){
	if(mp[x]) return mp[x];
	mp[x] = ++cur; return cur;
}

int n, m, dif[N], gas[N], x, y, type, diff, Arr[N], Brr[N], cntA, cntB, idx[N], r, b;

int main(){
///	freopen("in.txt", "r", stdin);
	Graph.init();
	scanf("%d %d", &n, &m);
	scanf("%d %d", &r, &b);

	for(int i = 1; i <= n; i ++){
		scanf("%d %d", &x, &y);
		x = get_id(x<<1), y = get_id(y<<1|1);
		gas[x] ++, gas[y] ++;
		dif[x] = dif[y] = 1000000;
		idx[i] = Graph.cnt;
		Graph.insert_Edge(x, y, 1);
		Arr[cntA++] = x;
		Brr[cntB++] = y;
	}

	for(int i = 1; i <= m; i ++){
		scanf("%d %d %d", &type, &x, &diff);
		if(type == 1){
			x = mp[x<<1];
			chkmin(dif[x], diff);
		}
		else{
			x = mp[x<<1|1];
			chkmin(dif[x], diff);
		}
		if( diff == 0 && (gas[x] & 1)){ puts("-1"); return 0; }
	}

	sort(Arr, Arr + cntA);
	cntA = unique(Arr, Arr + cntA) - Arr;
	sort(Brr, Brr + cntB);
	cntB = unique(Brr, Brr + cntB) - Brr;

	int S = ++ cur, T = ++ cur;

	for(int i = 0; i < cntA; i ++){ x = Arr[i];
		Graph.add_Edge(S, x, max(gas[x] - dif[x] + 1, 0) / 2, (gas[x] + dif[x]) / 2);
	}
	for(int i = 0; i < cntB; i ++){ x = Brr[i];
		Graph.add_Edge(x, T, max(gas[x] - dif[x] + 1, 0) / 2, (gas[x] + dif[x]) / 2);
	}
	LL flow = Graph.MaxFlow(S, T, cur + 1);

	if(flow == -1){ puts("-1"); return 0; }

	cout << flow * min(r, b) + (n - flow) * max(r, b) << endl;
	for(int i = 1; i <= n; i ++){
		if((r < b) ^ (Graph.cap[idx[i]])) printf("r");
		else printf("b");
	}
}