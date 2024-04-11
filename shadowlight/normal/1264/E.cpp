#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 57;

int gr[N][N];
int add_e[N], cnt[N];

void init() {
	for (int i = 0; i < N; i++) {
		add_e[i] = 2 * i + 1;
	}
}

struct MinCostMaxFlow {
    struct Edge{
        int to, cap;
        int flow;
        int cost;
    };

    static const int MAX_V = 3003;
    static const int MAX_E = 2 * 333 * 333;
    static const int INF = 1e9 + 7;
    static const int MAX_COST = 1e9 + 7; // change to ll if it is exceeded in FB

    int sz = 0;
    Edge e[MAX_E];
    vector<int> g[MAX_V];
    int dp[MAX_V];
    pair<int, int> prev[MAX_V];
    int phi[MAX_V];

    void addEdge(int v, int to, int cap, int cost){
        g[v].push_back(sz);
        e[sz++] = { to, cap, 0, cost };
        g[to].push_back(sz);
        e[sz++] = { v, 0, 0, -cost };
    }

    void calcPhi(int start) {
        // FB for calculating phi, add vertex q and q->v for all v with cost 0
        for (int i = 0; i < MAX_V; ++i) phi[i] = MAX_COST;
        phi[start] = 0;
        for (int k = 0; k < MAX_V; k++) {
            for (int v = 0; v < MAX_V; v++) {
                for (int to : g[v]) {
                    Edge &ed = e[to];
                    if (ed.cap == ed.flow) continue;
                    phi[ed.to] = min(phi[ed.to], phi[v] + ed.cost);
                }
            }
        }
    }

    ll find(int start, int finish, int required_flow) {
        calcPhi(start);

        ll ans = 0;

        while (required_flow) {
            for (int i = 0; i < MAX_V; i++) dp[i] = INF, prev[i] = { -1, -1 };
            dp[start] = 0;

            set< pair<int, int> > se;
            se.insert({ 0, start });

            while (!se.empty()) {
                auto [dist, v] = *se.begin(); se.erase(se.begin());
                for (int to : g[v]) {
                    auto ed = e[to];
                    if (ed.flow < ed.cap && dp[ed.to] > dp[v] + ed.cost - phi[ed.to] + phi[v]) {
                        prev[ed.to] = { v, to };
                        se.erase({ dp[ed.to], ed.to });
                        dp[ed.to] = dp[v] + ed.cost - phi[ed.to] + phi[v];
                        se.insert({ dp[ed.to], ed.to });
                    }
                }
            }

            if (dp[finish] == INF) {
                return -1;
            }

            int max_flow = required_flow;
            int v = finish;
            while (1) {
                auto now = prev[v];
                if (now.x == -1) break;
                max_flow = min(max_flow, e[now.y].cap - e[now.y].flow);
                v = now.x;
            }
            ans += (dp[finish] + phi[finish]) * (ll)max_flow;

            v = finish;
            while (1) {
                auto now = prev[v];
                if (now.x == -1) break;
                e[now.y].flow     += max_flow;
                e[now.y ^ 1].flow -= max_flow;
                v = now.x;
            }
            required_flow -= max_flow;

            // recalc phi
            int min_phi = 0;
            for (int i = 0; i < MAX_V; ++i) {
                if (dp[i] == INF) {
                    min_phi = min(min_phi, phi[i]);
                } else {
                    phi[i] += dp[i];
                }
            }
            for (int i = 0; i < MAX_V; ++i) {
                if (dp[i] == INF) {
                    phi[i] -= min_phi;
                }
            }
            //
        }

        return ans;
    }
} min_cost_max_flow;

int res[N][N];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		cnt[v]++;
		gr[v][u] = 1;
		res[v][u] = 1;
	}

	int rem = n * (n - 1) / 2 - m;

	int lst = 0;

	int NN = rem + n + 2, s = NN - 1, t = NN - 2;
	vector <pair <int, int> > kek;
	for (int i = 0; i < n; i++) {;
		for (int j = cnt[i]; j <= n; j++) {
			min_cost_max_flow.addEdge(i + rem, t, 1, add_e[j]);
		}
		for (int j = i + 1; j < n; j++) {
			if (gr[i][j] + gr[j][i] > 0) continue;
			min_cost_max_flow.addEdge(s, lst, 1, 0);
			min_cost_max_flow.addEdge(lst, i + rem, 1, 0);
			min_cost_max_flow.addEdge(lst++, j + rem, 1, 0);
			kek.push_back({i, j});
		}
	}
	assert(kek.size() == rem);
	min_cost_max_flow.find(s, t, rem);
	for (int i = 0; i < rem; i++) {
		for (int ed : min_cost_max_flow.g[i]) {
			auto edge = min_cost_max_flow.e[ed];
			if (edge.flow < 1) continue;
			int v = kek[i].first, u = kek[i].second;
			if (edge.to == u + rem) swap(v, u);
			res[v][u] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && !res[i][j] && !res[j][i]) {
				assert(false);
			}
			cout << res[i][j];
		}
		cout << "\n";
	}
}