#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5, Base = 1949, P = 998244353;
int n, m, hsh[N], pw[N], ans[N];
int fer[256][256];
int cnt[10];

struct Graph {
	int lnkL[N], lnkR[N], lnkD[N], lnkU[N];
	int col[N], vis[N];
	struct Cycle { 
		vector<int> col, id; int hsh;
		Cycle() { col.clear(), id.clear(), hsh = 0; }
		bool operator <(Cycle b) const { return hsh == b.hsh? col[0] < b.col[0] : hsh < b.hsh; }
	} cir[N];
	int sze;
	
	struct Edge { int v, nxt, w; } edge[N << 1];
	int head[N], tot;
	
	void add(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }

	void push(char op, int x, int id) {
		if(op == 'L') lnkL[x] = id;
		if(op == 'R') lnkR[x] = id;
		if(op == 'B') lnkD[x] = id;
		if(op == 'T') lnkU[x] = id;
	}
	
	void GetCir(int u, int lst) {
		if(vis[u]) return; vis[u] = 1;
		cir[sze].col.push_back(col[u]);
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = edge[i].w;
			if(v == lst) continue;
			cir[sze].id.push_back(w), GetCir(v, u); 
		}
	}
	
	Cycle GetMin(Cycle a) {
		static int tmpc[N], tmpi[N], top, pos, mn, ber;
		Cycle res, ires;
		top = 0, pos = 0, mn = 0x3f3f3f3f;
		for(int i = 0; i < a.col.size(); i++) ++top, tmpc[top] = a.col[i], tmpi[top] = a.id[i];
		for(int i = 1; i <= top; i++) tmpc[top + i] = tmpc[i], tmpi[top + i] = tmpi[i];
		for(int i = 1; i <= top * 2; i++) hsh[i] = (1ll * hsh[i - 1] * Base + tmpc[i]) % P;
		for(int i = 1; i <= top; i++) {
			int nw = (hsh[i + top - 1] - 1ll * hsh[i - 1] * pw[top] % P + P) % P;
			if(nw < mn) mn = nw, pos = i;
		}
		res.hsh = mn;
		for(int i = 1; i <= top; i++) res.col.emplace_back(tmpc[i + pos - 1]), res.id.emplace_back(tmpi[i + pos - 1]);
		reverse(tmpc + 1, tmpc + 1 + top * 2), reverse(tmpi + 1, tmpi + 1 + top * 2);
		ber = tmpi[1]; for(int i = 1; i < top * 2; i++) tmpi[i] = tmpi[i + 1]; tmpi[top * 2] = ber;
		pos = 0, mn = 0x3f3f3f3f;
		for(int i = 1; i <= top * 2; i++) hsh[i] = (1ll * hsh[i - 1] * Base + tmpc[i]) % P;
		for(int i = 1; i <= top; i++) {
			int nw = (hsh[i + top - 1] - 1ll * hsh[i - 1] * pw[top] % P + P) % P;
			if(nw < mn) mn = nw, pos = i;
		}
		ires.hsh = mn;
		for(int i = 1; i <= top; i++) ires.col.emplace_back(tmpc[i + pos - 1]), ires.id.emplace_back(tmpi[i + pos - 1]);
		Cycle der = min(res, ires);
		if(der.col.size() == 2) sort(der.id.begin(), der.id.end());
		return der;
	} 
	
	void build() {
		for(int i = 1; i <= n; i++) if(!lnkL[i] || !lnkR[i]) cout << "No solution" << endl, exit(0);
		for(int i = 1; i <= m; i++) if(!lnkD[i] || !lnkU[i]) cout << "No solution" << endl, exit(0);
		for(int i = 1; i <= n; i++) add(lnkL[i], lnkR[i], i), add(lnkR[i], lnkL[i], i);
		for(int i = 1; i <= m; i++) add(lnkD[i], lnkU[i], i + n), add(lnkU[i], lnkD[i], i + n);
		for(int i = 1; i <= n + m; i++) if(!vis[i]) ++sze, GetCir(i, 0), cir[sze] = GetMin(cir[sze]);
		sort(cir + 1, cir + 1 + sze);
	}
	
	void Debug() {
		cout << "number of cycles: " << sze << endl;
		for(int i = 1; i <= sze; i++) {
			cout << "cycle " << i << ": " << cir[i].hsh << "\n";
			for(auto v: cir[i].col) cout << v << " "; cout << endl;
			for(auto v: cir[i].id) cout << v << " "; cout << endl;
		}
	}
} F, G;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	fer['B']['T'] = fer['T']['B'] = 1, fer['L']['R'] = fer['R']['L'] = 2;
	fer['L']['T'] = fer['T']['L'] = 3, fer['T']['R'] = fer['R']['T'] = 4;
	fer['R']['B'] = fer['B']['R'] = 5, fer['B']['L'] = fer['L']['B'] = 6;
	pw[0] = 1; for(int i = 1; i <= 2 * (n + m); i++) pw[i] = 1ll * pw[i - 1] * Base % P;
	for(int i = 1; i <= n + m; i++) {
		char op1, op2; int x, y;
		cin >> op1 >> op2 >> x >> y;
		++cnt[fer[op1][op2]];
		F.push(op1, x, i), F.push(op2, y, i);
		F.col[i] = fer[op1][op2];
	}
	if(cnt[1] && cnt[2]) return cout << "No solution" << endl, 0;
	if(cnt[3] != cnt[5] || cnt[4] != cnt[6]) return cout << "No solution" << endl, 0;
	int nw = 0;
	for(int i = 1; i <= cnt[1]; i++) ++nw, G.col[nw] = 1, G.push('T', i + cnt[3], nw), G.push('B', i + cnt[6], nw);
	for(int i = 1; i <= cnt[2]; i++) ++nw, G.col[nw] = 2, G.push('L', i + cnt[3], nw), G.push('R', i + cnt[4], nw);
	for(int i = 1; i <= cnt[3]; i++) ++nw, G.col[nw] = 3, G.push('L', i, nw), G.push('T', i, nw);
	for(int i = 1; i <= cnt[4]; i++) ++nw, G.col[nw] = 4, G.push('T', m - i + 1, nw), G.push('R', i, nw);
	for(int i = 1; i <= cnt[5]; i++) ++nw, G.col[nw] = 5, G.push('B', m - i + 1, nw), G.push('R', n - i + 1, nw);
	for(int i = 1; i <= cnt[6]; i++) ++nw, G.col[nw] = 6, G.push('B', i, nw), G.push('L', n - i + 1, nw);
	F.build(), G.build();
//	F.Debug(), G.Debug();
	if(F.sze != G.sze) return cout << "No solution" << endl, 0;
	for(int i = 1; i <= F.sze; i++) {
		if(F.cir[i].hsh != G.cir[i].hsh || F.cir[i].col.size() != G.cir[i].col.size()) 
			return cout << "No solution" << endl, 0;
		for(int j = 0; j < F.cir[i].col.size(); j++)
			ans[G.cir[i].id[j]] = F.cir[i].id[j];
	}
	for(int i = 1; i <= n + m; i++) if(ans[i] > n) ans[i] = ans[i] - n;
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	for(int i = 1; i <= m; i++) cout << ans[i + n] << " ";
	return 0;
}

/*
2 2
T L 1 2
B R 2 1
T L 2 1
B R 1 2
*/