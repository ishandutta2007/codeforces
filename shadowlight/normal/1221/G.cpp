#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 47;
const int SZ = 20;

vector <int> c, pos;
vector <vector <int> > gr;

int now = 1;

vector <vector <int> > comp;
vector <pair <int, int> > edges;

void dfs(int v) {
	if (c[v]) return;
	comp.back().push_back(v);
	pos[v] = comp.back().size() - 1;
	c[v] = now;
	for (int u : gr[v]) {
		dfs(u);
	}
}

vector <int> num;

bool dfs2(int v, int x) {
	if (num[v]) {
		return num[v] == x;
	}
	num[v] = x;
	for (int u : gr[v]) {
		if (!dfs2(u, 3 - x)) {
			return false;
		}
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	c.resize(n, 0);
	pos.resize(n, -1);
	gr.resize(n);
	num.resize(n, 0);

	vector <int> edge_mask(n, 0);
	vector <int> toSec(n, 0);
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].push_back(u);
		gr[u].push_back(v);
		edges.push_back({v, u});
	}

	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			comp.push_back({});
			dfs(i);
			now++;
			//cout << comp.back().size() << "\n";
		}
	}

	for (auto e : edges) {
		int v = e.first, u = e.second;
		if ((pos[v] >= SZ) != (pos[u] >= SZ)) {
			toSec[v] += (1 << (pos[u] >= SZ ? pos[u] - SZ : pos[u]));
			toSec[u] += (1 << (pos[v] >= SZ ? pos[v] - SZ : pos[v]));	
		} else {
			edge_mask[v] += (1 << (pos[u] >= SZ ? pos[u] - SZ : pos[u]));
			edge_mask[u] += (1 << (pos[v] >= SZ ? pos[v] - SZ : pos[v]));	
		}
	}

	vector <ll> dp(8, 0);

	dp[0] = 1;

	for (int i = 0; i < (int) comp.size(); i++) {
		/*for (int v : comp[i]) {
			cout << v << " ";
		}
		cout << "\n";*/
		ll sz = comp[i].size();
		vector <ll> ndp(8, 0);
		if (comp[i].size() == 1) {
			ndp[0] = 2;
		} else {
			bool bip = dfs2(comp[i][0], 1);
			ndp[1] = 1;
			ndp[2] = 1;
			if (bip) {
				ndp[4] = 2;
			}

			vector <int> fir, sec;
			for (int j = 0; j < (int) comp[i].size(); j++) {
				if (j < SZ) {
					fir.push_back(comp[i][j]);
				} else {
					sec.push_back(comp[i][j]);
				}
			}
			int szf = fir.size(), szs = sec.size();
			
			assert(szf <= SZ && szs <= SZ);

			vector <ll> good_submasks(1 << szs, 0);
			good_submasks[0] = 1;
			for (int mask = 0; mask < (1 << szs); mask++) {
				for (int j = 0; j < szs; j++) {
					if (mask & (1 << j)) {
						int v = sec[j];
						good_submasks[mask] += good_submasks[mask ^ (1 << j)]; 
						int mask_u = edge_mask[v];
						good_submasks[mask] += good_submasks[mask ^ (1 << j) ^ (mask_u & mask)];
						break;
					}
				}
			}
			for (int mask = 0; mask < (1 << szf); mask++) {
				bool can = true;
				for (int j = 0; j < szf; j++) {
					if (mask & (1 << j)) {
						int v = fir[j];
						int mask_u = edge_mask[v];
						if (mask_u & mask) {
							can = false;
							break;
						} 
					}
				}
				if (!can) continue;
				//cout << mask << "\n";
				assert(mask != (1 << szf) - 1);
				int now_mask = (1 << szs) - 1;
				for (int j = 0; j < szf; j++) {
					if (mask & (1 << j)) {
						int v = fir[j];
						int mask_u = toSec[v];
						now_mask &= ~mask_u;
					}
				}
				ndp[5] += good_submasks[now_mask];
			}
			ndp[5]--;
			if (bip) {
				ndp[5] -= 2;
			}
			ndp[6] = ndp[5];
		}

		ll all = (1LL << sz);
		ndp[7] = (all - ndp[1] - ndp[2] - ndp[4] - 2LL * ndp[5] - ndp[0]);
		
		/*for (int i = 0; i < 8; i++) {
			cout << ndp[i] << " ";
		}
		cout << "\n";
*/
		vector <ll> dpp(8, 0);
		for (int mi = 0; mi < 8; mi++) {
			for (int mj = 0; mj < 8; mj++) {
				dpp[mi | mj] += dp[mi] * ndp[mj];
			}
		}
		dp = dpp;
	}
	cout << dp[7] << "\n";
}