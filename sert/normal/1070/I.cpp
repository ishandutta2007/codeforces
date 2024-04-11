#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define up_bo(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()

using namespace std;

typedef long long ll;

void setmin(int &x, int y){
	x = min(x, y);
}

void setmax(int &x, int y){
	x = max(x, y);
}

void setmin(ll &x, ll y){
	x = min(x, y);
}

void setmax(ll &x, ll y){
	x = max(x, y);
}

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, maxw = (1 << 19) + 10, inf = 1e9 + 100, mod = 1e9 + 993;

const int INF = (int)1e9 + 34;

struct Edge {
    int v, f, c;
    int back_num;
    Edge(int v = 0, int f = 0, int c = 0) {
        this->v = v;
        this->f = f;
        this->c = c;
    }
};

struct Graph {
    int n, m;
    vector<vector<Edge>> es;

    Graph(int sz) {
        n = sz;
        es.resize(n);
        for (int i = 0; i < n; i++) {
            es[i].clear();
        }
    }

    void addEdge(int v1, int v2, int c = 1) {
        es[v1].push_back({v2, 0, c});
        es[v2].push_back({v1, c, c});
        es[v1].back().back_num = (int)es[v2].size() - 1;
        es[v2].back().back_num = (int)es[v1].size() - 1;
    }

    vector<int> getDist(int pow2) {
        vector<int> d(n, INF);
        d[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto edge: es[v]) {
                if (edge.f < edge.c && d[edge.v] == INF && edge.c - edge.f >= pow2) {
                    d[edge.v] = d[v] + 1;
                    q.push(edge.v);
                }
            }
        }
        return d;
    }

    bool getBlockingFlow(int v, vector<int> &curEdge, const vector<int> &d, int pow2) {
        if (v == n - 1) {
            return true;
        }

        for (int i = curEdge[v]; i < (int)es[v].size(); i++) {
            curEdge[v] = i;
            auto &edge = es[v][i];

            if (d[edge.v] != d[v] + 1 || edge.c - edge.f < pow2) {
                continue;
            }

            if (getBlockingFlow(edge.v, curEdge, d, pow2)) {
                edge.f += pow2;
                es[edge.v][edge.back_num].f -= pow2;
                return true;
            }
        }
        return false;
    }

    ll findMaxFlow() {
        ll maxFlow = 0;
        while (true) {
            auto d = getDist(1);
            if (d.back() == INF) {
                break;
            }
            vector<int> curEdge(n, 0);
            while (getBlockingFlow(0, curEdge, d, 1))
                maxFlow++;
        }
        return maxFlow;
    }
};

int main() {
#ifdef MADE_BY_SERT
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#else
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--){
        int n, m, k;
        cin >> n >> m >> k;
        Graph q(n + m + 2);
        vector<pair<int, int> > ed(m);
        vector<int> deg(n);
        for (int i = 0; i < m; i++)
            cin >> ed[i].fr >> ed[i].sc, ed[i].fr--, ed[i].sc--,
            q.addEdge(0, i + 1),
            q.addEdge(i + 1, m + ed[i].fr + 1),
            q.addEdge(i + 1, m + ed[i].sc + 1),
            deg[ed[i].fr]++, deg[ed[i].sc]++;
        int ans = 0;
        for (int i = 0; i < n; i++)
            q.addEdge(m + i + 1, n + m + 1, max(0, 2 * (deg[i] - k))),
            ans += max(0, 2 * (deg[i] - k));
        if (q.findMaxFlow() != ans){
            for (int i = 0; i < m; i++)
                cout << 0 << ' ';
            continue;
        }
        vector<int> col(m);
        vector<vector<int> > e(n);
        int cnt = 1;
        for (int i = 0; i < m; i++)
        if (q.es[i + 1][1].f)
            e[q.es[i + 1][1].v - m - 1].push_back(i);
        else
        if (q.es[i + 1][2].f)
            e[q.es[i + 1][2].v - m - 1].push_back(i);
        else
            col[i] = cnt++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < e[i].size(); j += 2)
                col[e[i][j]] = cnt, col[e[i][j + 1]] = cnt++;
        for (int i : col)
            cout << i << ' ';
        cout << '\n';
    }
}