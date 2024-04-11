#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, a[N], b[N], cnt[N], ban;
int low[N], dfn[N], ins[N], tim, flag;
stack<int> st; 
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void tarjan(int u) {
	low[u] = dfn[u] = ++tim, ins[u] = 1, st.push(u);
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == ban) continue;
		if(v == u) flag = 1;
		if(!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
		else if(ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		while(st.top() != u) flag = 1, ins[st.top()] = 0, st.pop();
		ins[u] = 0, st.pop();
	}
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), cnt[i] = low[i] = dfn[i] = head[i] = 0; 
	tim = 0, tot = 0, flag = 0;
	for(int i = 1; i <= n; i++) b[i] = get(), ++cnt[b[i]], add(a[i], b[i]);
	ban = 0;
	for(int i = 1; i <= n; i++) if(cnt[i] > cnt[ban]) ban = i;
	for(int i = 1; i <= n; i++) if(i != ban && !dfn[i]) tarjan(i);
	if(flag) cout << "WA" << endl;
	else cout << "AC" << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}