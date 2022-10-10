#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Edge {
    int u, v;
    long long cap, flow;

    Edge(int _u, int _v, long long _cap) : u(_u), v(_v), cap(_cap), flow(0) {}
};

struct Dinic {
    int m, s, t;
    vector<int> level, ptr;
    vector<Edge> edges;
    vector<vector<int>> adj;

    Dinic(int n, int _s, int _t) : m(0), s(_s), t(_t), level(n), ptr(n), adj(n) {}

    void addEdge(int u, int v, long long cap, long long rcap = 0) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, rcap);
        adj[u].push_back(m++);
        adj[v].push_back(m++);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int e : adj[u])
                if (edges[e].cap - edges[e].flow > 0 && level[edges[e].v] == -1) {
                    level[edges[e].v] = level[u] + 1;
                    q.push(edges[e].v);
                }
        }
        return level[t] != -1;
    }

    long long dfs(int u, long long f) {
        if (u == t)
            return f;
        while (ptr[u] < (int) adj[u].size()) {
            int e = adj[u][ptr[u]], v = edges[e].v;
            long long nf;
            if (level[u] + 1 == level[v] && edges[e].cap - edges[e].flow > 0 && (nf = dfs(v, min(f, edges[e].cap - edges[e].flow))) > 0) {
                edges[e].flow += nf;
                edges[e^1].flow -= nf;
                return nf;
            }
            ptr[u]++;
        }
        return 0;
    }

    long long maxFlow() {
        long long ret = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long f = dfs(s, LLONG_MAX))
                ret += f;
        }
        return ret;
    }
};

const int MAX = 2e6 + 5;
const int INF = 2e9;

bitset<MAX> prime;
vector<int> primeList;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for (int i=4; i<MAX; i+=2)
        prime[i] = 0;
    for (int p=3; p<MAX; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            for (int i=p; i<=(MAX-1)/p; i+=2)
                prime[i*p] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, k;
    cin >> n >> k;
    vector<int> p(n), c(n), l(n);
    for (int i=0; i<n; i++)
        cin >> p[i] >> c[i] >> l[i];

    int lo = 1, hi = n + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2, tot = 0, mxOne = -1;
        Dinic dinic(n + 2, n, n + 1);
        for (int i=0; i<n; i++)
            if (l[i] <= mid) {
                if (c[i] == 1) {
                    if (mxOne == -1 || p[i] > p[mxOne])
                        mxOne = i;
                } else {
                    tot += p[i];
                    if (c[i] % 2)
                        dinic.addEdge(dinic.s, i, p[i]);
                    else
                        dinic.addEdge(i, dinic.t, p[i]);
                }
            }
        if (mxOne != -1) {
            tot += p[mxOne];
            dinic.addEdge(dinic.s, mxOne, p[mxOne]);
        }
        for (int i=0; i<n; i++)
            if (l[i] <= mid && (c[i] != 1 || i == mxOne))
                for (int j=i+1; j<n; j++)
                    if (l[j] <= mid && (c[j] != 1 || j == mxOne) && prime[c[i] + c[j]]) {
                        if (c[i] % 2)
                            dinic.addEdge(i, j, INF);
                        else
                            dinic.addEdge(j, i, INF);
                    }
        if (tot - dinic.maxFlow() >= k)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << (lo > n ? -1 : lo) << "\n";

    return 0;
}