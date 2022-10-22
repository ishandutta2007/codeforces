#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 4 * 207 * 207; //count of vertices

    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int cap){
        g[a].pb(e.size());
        e.pb({b, 0, cap});
        g[b].pb(e.size());
        e.pb({a, 0, 0});
    }

    int minFlow, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;
        vector<int> st;
        int uk = 0;
        st.pb(start);
        while(uk < st.size()){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st.pb(ed.to);
                }
            }
        }
        return dp[finish] != -1;
    }

    int dfs(int v, int flow){
        if (v == finish) return flow;
        for (; ptr[v] < g[v].size(); ptr[v]++){
            int to = g[v][ptr[v]];
            edge ed = e[to];
            if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1){
                int add = dfs(ed.to, min(flow, ed.cap - ed.flow));
                if (add){
                    e[to].flow += add;
                    e[to ^ 1].flow -= add;
                    return add;
                }
            }
        }
        return 0;
    }

    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        for (minFlow = (1 << 30); minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector <vector <bool> > field(n, vector <bool> (m));
	vector<vector <int>> right(n, vector<int>(m, -1));  
	vector<vector <int>> down(n, vector<int>(m, -1));  

	int now = 2;

	int total = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char x;
			cin >> x;
			field[i][j] = (x == '#');
			total += field[i][j];
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j] && field[i + 1][j]) {
				down[i][j] = now++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (field[i][j] && field[i][j + 1]) {
				right[i][j] = now++; 
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (down[i][j] != -1) {
				dinic.addEdge(0, down[i][j], 1);
			}
			if (right[i][j] != -1) {
				dinic.addEdge(right[i][j], 1, 1);
			}
			if (right[i][j] != -1 && down[i][j] != -1) {
				dinic.addEdge(down[i][j], right[i][j], 1);
			}
			if (i + 1 < n && right[i + 1][j] != -1 && down[i][j] != -1) {
				dinic.addEdge(down[i][j], right[i + 1][j], 1);
			}
			if (j && right[i][j - 1] != -1 && down[i][j] != -1) {
				dinic.addEdge(down[i][j], right[i][j - 1], 1);
			}
			if (i + 1 < n && j && right[i + 1][j - 1] != -1 && down[i][j] != -1) {
				dinic.addEdge(down[i][j], right[i + 1][j - 1], 1);
			}
		}
	}
	int res = dinic.dinic(0, 1);
	//cout << res << "\n";
	int ind = (now - 2) - res;
	cout << total - ind << "\n";
}