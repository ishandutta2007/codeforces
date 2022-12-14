// In the name of God

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


const int N = (int) 1e3 + 3;
int n, m, mark[N * 2], ql[N], qr[N], comp[N * 2];
vector<int> adj[N * 2], rev[N * 2];
void add_edge(int u, int v) { 
    adj[u].push_back(v); 
    rev[v].push_back(u);
}

void add_clause(int u, int v) {
    for (int i = 0; i < 2; ++i) {
	add_edge(u << 1 | i, v << 1 | (i ^ 1));
	add_edge(v << 1 | i, u << 1 | (i ^ 1));
    }
}
int in(int l, int m, int r) { return (l < m && m < r); }

bool intersect(int al, int ar, int bl, int br) {
    if (al == bl || al == br || ar == br || ar == bl) return 0;
    return in(al, bl, ar) ^ in(al, br, ar);
}

int q[N * 2], t;
void dfs(int v) {
    if (mark[v]++) return;
    for (int u : adj[v])
	dfs(u);
    q[t++] = v;
}

void sfd(int v, int c) {
    if (mark[v]++) return;
    comp[v] = c;
    for (int u : rev[v])
	sfd(u, c);
}


int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
	cin >> ql[i] >> qr[i];
	ql[i]--;
	qr[i]--;
	if (qr[i] < ql[i]) swap(ql[i], qr[i]);
    }
    for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
	    if (intersect(ql[i], qr[i], ql[j], qr[j])) {
		add_clause(i, j);
	    }
    for (int v = 0; v < 2 * n; ++v)
	if (!mark[v])
	    dfs(v);
    memset(mark, 0, sizeof mark);
    int cnt = 0;
    for (int i = 2 * n - 1; i >= 0; --i)
	if (!mark[q[i]])
	    sfd(q[i], cnt++);
    for (int v = 0; v < n; ++v)
	if (comp[v << 1 | 0] == comp[v << 1 | 1]) {
	    cout << "Impossible";
	    return 0;
	}
    for (int v = 0; v < n; ++v)
	cout << (comp[v << 1 | 0] > comp[v << 1 | 1]? 'i': 'o');
}