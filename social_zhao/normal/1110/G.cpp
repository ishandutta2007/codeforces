#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1000005;
int n, node;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, deg[N], LeaF[N];
char s[N];

void clear() {
	for(int i = 1; i <= node; i++) head[i] = deg[i] = LeaF[i] = 0;
	for(int i = 1; i <= tot; i++) edge[i] = (Edge){ 0, 0 };
	node = tot = 0; 
}

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot, deg[v]++; }
void ins(int u, int v) { add(u, v), add(v, u); }

bool solve() {
	n = get(), node = n;
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), ins(u, v);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) if(s[i] == 'W') node++, ins(i, node), ins(node, node + 1), ins(node, node + 2), node += 2;
	int cntLeaF = 0;
	for(int i = 1; i <= node; i++) if(deg[i] == 1) LeaF[i] = 1, cntLeaF++;
	for(int u = 1; u <= node; u++) {
		if(deg[u] >= 4) return 1;
		if(deg[u] == 3) {
			int cnt = 0;
			for(int i = head[u]; i; i = edge[i].nxt) if(!LeaF[edge[i].v]) cnt++;
			if(cnt >= 2) return 1;
		}
	}
	if(cntLeaF == 4) {
		for(int u = 1; u <= node; u++) if(LeaF[u]) {
			int v = edge[head[u]].v;
			deg[v]--;
		}
		int cnt = 0;
		for(int i = 1; i <= node; i++) if(!LeaF[i]) cnt += deg[i] == 1;
		if(cnt == 2 && (node & 1)) return 1; 
	}
	return 0;
}

int main() {
	int T = get();
	while(T--) {
		int res = solve();
		if(res) printf("White\n");
		else printf("Draw\n");
		clear();
	}
	return 0;
}