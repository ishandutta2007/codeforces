#include <bits/stdc++.h>
#define ll long long
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

struct MinCostMaxFlow {
    struct Edge{
        int to, cap;
        int flow;
        int cost;
        int index;
    };

    static const int MAX_V = 422;
    static const int MAX_E = 4444;

    int sz = 0;
    Edge e[MAX_E];
    vector<int> g[MAX_V];
    int fb[MAX_V];
    int was[MAX_V];
    pair<int, int> prev[MAX_V];

    void addEdge(int v, int to, int cap, int cost, int index = -1){
        g[v].push_back(sz);
        e[sz++] = { to, cap, 0, cost, index};
        g[to].push_back(sz);
        e[sz++] = { v, 0, 0, -cost, index};
    }

    void addOneEdge(int v, int to, int cap, int cost, int index){
        g[v].push_back(sz);
        e[sz++] = { to, cap, 0, cost, index};
    }

    ll find(int start, int finish, int required_flow) {
        ll ans = 0;

        while (required_flow) {
            for (int i = 0; i < MAX_V; i++) fb[i] = INF, prev[i] = { -1, -1 }, was[i] = 0;
	            fb[start] = 0;
	            vector<int> st;
	            int uk = 0;
	            st.push_back(start);
	            while (uk < st.size()) {
	                int v = st[uk++];
					was[v] = 0;
	                for (int to : g[v]) {
	                    auto ed = e[to];
	                    if (ed.flow < ed.cap && fb[ed.to] > fb[v] + ed.cost) {
	                        prev[ed.to] = { v, to };
	                        fb[ed.to] = fb[v] + ed.cost;
	                        if (!was[ed.to]) {
			    	    st.push_back(ed.to);
				    	was[ed.to] = 1;
					}
                }
            }
        }

        if (fb[finish] == INF) {
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
            ans += fb[finish] * (ll)max_flow;

            v = finish;
            while (1) {
                auto now = prev[v];
                if (now.x == -1) break;
                e[now.y].flow     += max_flow;
                e[now.y ^ 1].flow -= max_flow;
                v = now.x;
            }
            required_flow -= max_flow;
        }

        return ans;
    }
} min_cost_max_flow;

main(){
#ifdef LOCAL
	freopen("K_input.txt", "r", stdin);
	//freopen("K_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int na, nb, m, r, b;
	cin >> na >> nb >> m >> r >> b;

	int s = na + nb, t = s + 1;

	int cnta = 0, cntb = 0;

	for (int i = 0; i < na; i++) {
		char c;
		cin >> c;
		if (c == 'R') {
			min_cost_max_flow.addEdge(s, i, 1, -INF);
			min_cost_max_flow.addEdge(s, i, INF, 0);
			cnta++;
		} else if (c == 'B') {
			min_cost_max_flow.addEdge(i, t, 1, -INF);
			min_cost_max_flow.addEdge(i, t, INF, 0);
			cntb++;
		} else {
			min_cost_max_flow.addEdge(s, i, INF, 0);
			min_cost_max_flow.addEdge(i, t, INF, 0);
		}
	}

	for (int i = na; i < nb + na; i++) {
		char c;
		cin >> c;
		if (c == 'B') {
			min_cost_max_flow.addEdge(s, i, 1, -INF);
			min_cost_max_flow.addEdge(s, i, INF, 0);
			cnta++;
		} else if (c == 'R') {
			min_cost_max_flow.addEdge(i, t, 1, -INF);
			min_cost_max_flow.addEdge(i, t, INF, 0);
			cntb++;
		} else {
			min_cost_max_flow.addEdge(s, i, INF, 0);
			min_cost_max_flow.addEdge(i, t, INF, 0);
		}
	}
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		min_cost_max_flow.addEdge(v, u + na, 1, r, i);
		min_cost_max_flow.addEdge(u + na, v, 1, b, i);
	}
	min_cost_max_flow.addEdge(s, t, INF, 0);
	min_cost_max_flow.find(s, t, cnta + cntb);
	ll res = 0;
	bool bad = false;
	vector <char> ans(m, 'U');
	for (int i = 0; i < min_cost_max_flow.sz; i++) {
		auto e = min_cost_max_flow.e[i];
		if (e.cap != 1) continue;
		if (e.flow == e.cap) {
			if (e.cost == -INF) continue;
			res += e.cost;
			ans[e.index] = (e.to >= na ? 'R' : 'B');
		} else {
			if (e.cost == -INF) {
				cout << "-1\n";
				exit(0);
			}
		}
	}
	cout << res << "\n";
	for (int i = 0; i < m; i++) {
		cout << ans[i];
	}

}