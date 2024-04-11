#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
#define MX 500005

int N, M, Q, Tot;
int P[MX], val[MX], root[4 * MX];
int L[MX * 4], R[MX * 4], st[MX * 4], en[MX * 4], pos[MX];
bool chk[MX], vis[MX], op[MX];

vector<int> Arr;

struct Edge {
	int s, e;
	void in() { cin >> s >> e; s --, e --; }
} E[MX];

int find_root(int u) {
	if(root[u] == u) return u;
	return root[u] = find_root(root[u]);
}

void dfs1(int u) {
	if(L[u] == 0 && R[u] == 0) {
		assert(u < N);
		st[u] = Arr.size();
		Arr.push_back(u);
		en[u] = Arr.size() - 1;
	}
	else {
		dfs1(L[u]), dfs1(R[u]);
		st[u] = min(st[L[u]], st[R[u]]);
		en[u] = max(en[L[u]], en[R[u]]);
	}
}

void merge(int i) {
	int u = find_root(E[i].s), v = find_root(E[i].e);
	if(u == v) return ;
	L[Tot] = u, R[Tot] = v;
	root[u] = root[v] = root[Tot] = Tot;
	Tot ++;
}

struct WinnerTree {
	int v[MX * 4];
	int Tot;
	void build(int an) {
		int i;
		for (Tot = 1; Tot < an; Tot *= 2);
		for (i = 0; i < an; i++) v[Tot + i] = P[Arr[i]];
		for (i = an; i < Tot; i++) v[Tot + i] = P[Arr[0]];
		for (i = Tot - 1; i > 0; i--) v[i] = max(v[i * 2], v[i * 2 + 1]);
	}
	void up(int i, int val) {
		i += Tot;
		v[i] = val;
		for (i /= 2; i; i /= 2) v[i] = max(v[i * 2], v[i * 2 + 1]);
	}
	int get(int st, int en) {
		int rlt = 0;
		st += Tot, en += Tot;
		while (st < en) {
			if (st & 1) rlt = max(rlt, v[st]);
			if (en & 1) rlt = max(rlt, v[en - 1]);
			st = (st + 1) / 2;
			en /= 2;
		}
		return rlt;
	}
} WT;

int main() {
//	freopen("in.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> Q;
	for(int i = 0; i < N; i ++) cin >> P[i];
	for(int i = 0; i < M; i ++) E[i].in();
	for(int i = 0; i < Q; i ++) {
		int tp;
		cin >> tp >> val[i]; val[i] --;
		op[i] = tp - 1;
		if(op[i]) chk[val[i]] = 1;
	}

	for(int i = 0; i < N; i ++) root[i] = i;
	Tot = N;
	for(int i = 0; i < M; i ++) if(!chk[i]) merge(i);
	for(int i = Q - 1; i >= 0; i --) if(op[i]) {
		for(int j = i + 1; op[j] == 0 && j < Q; j ++) {
			int u = val[j];
			val[j] = find_root(u);
		}
		merge(val[i]);
	}
	for(int i = 0; i < Q && !op[i]; i ++) {
		int u = val[i];
		val[i] = find_root(u);
	} 
	for(int i = 0; i < Tot; i ++) if(root[i] == i) dfs1(i);
	assert(Arr.size() == N);
	for(int i = 0; i < N; i ++) pos[P[Arr[i]]] = i;
		
	WT.build(N);
	for(int i = 0; i < Q; i ++) if(op[i] == 0) {
		int s = st[val[i]], e = en[val[i]];
		int ans = WT.get(s, e + 1);
		cout << ans << endl;
		if(ans == 0) continue;
		WT.up(pos[ans], 0);
	}
	
	return 0;
}