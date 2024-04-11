//In the name of God
// Break through! I screamed forth form my soul!

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;
const int oo = N;
set<pair<int, int>> st;
int best[N], d[N], cnt[N], mark[N];
vector<int> in[N], out[N];

void relax(int v) {
	mark[v] = 1;
	for (int i = 0; i < (int) in[v].size(); i++) {
		int u = in[v][i];
		if (mark[u])
			continue;
		st.erase({d[u], u});
		if (d[v] < best[u]) {
			cnt[u] = 0;
			best[u] = d[v];	
		}
		cnt[u] += (best[u] == d[v]);
		if (cnt[u] == (int) out[u].size())
			d[u] = best[u];
		else
			d[u] = best[u] + 1;
		st.insert({d[u], u});
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v); u--, v--;
		out[u].push_back(v);
		in[v].push_back(u);
		cnt[u]++;
	}
	for (int i = 0; i < n; i++)
		best[i] = d[i] = oo;
	int source, sink; scanf("%d%d", &source, &sink); source--, sink--;
	swap(sink, source);
	d[source] = 0;
	relax(source);
	while (st.size()) {
		pair<int, int> cur = *(st.begin()); st.erase(st.begin());
		int v = cur.second;
		if (mark[v])
			continue;
		relax(v);	
	}
	if (d[sink] > n) {
		puts("-1");	
	} else {
		printf("%d\n", d[sink]);	
	}
}