#include <bits/stdc++.h>

using namespace std;
#define maxn 200001
#define ti tuple<int, int, int>
int par[maxn];
bool cyc[maxn];
int ra[maxn];

int findset(int u) {
	if (par[u] == u) return u;
	par[u] = findset(par[u]);
	return par[u];
}

void unionset(int a, int b) {
	a = findset(a);
	b = findset(b);
	if (ra[a] > ra[b]) {
		par[b] = a;
		if (cyc[b]) cyc[a] = true;
	}
	else {
		par[a] = b;
		if (ra[a] == ra[b]) {
			ra[b]++;
			
		}
		if (cyc[a]) cyc[b] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		par[i] = i;
		cyc[i] = false;
		ra[i] = 1;
	}
	vector<ti> edge;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edge.push_back(make_tuple(w, a, b));
	}
	sort(edge.begin(), edge.end());
	reverse(edge.begin(), edge.end());
	int ans = 0;
	for (int i  = 0; i < m; i++) {
		a = get<1>(edge[i]);
		w = get<0>(edge[i]);
		b = get<2>(edge[i]);
		a = findset(a);
		b = findset(b);
		if (a == b) {
			if (!cyc[a]) {
				cyc[a] = true;
				ans += w;
			}
		}
		else {
			if (!(cyc[a] && cyc[b])) {
				ans += w;
				unionset(a, b);
			}
			
		}
	}
	cout << ans << endl;
	// cin >> ans;
}