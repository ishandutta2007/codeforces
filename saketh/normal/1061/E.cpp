#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define FU(i, a, b) for(decltype(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define pb push_back
#define sz(c) int((c).size())
const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const int NULO = -1; const double EPS = 1e-8;

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct graph {
  //////////////////////////////////////////////////////////////////////////////
  // Shared part. Also known as: You will need this!
  //
  vi dest;  // use sz(dest) as nar
  vvi adj;  // use sz(adj) as nvt
  int inv(int a) { return a ^ 0x1; }
  graph(int n = 0) {
    _ini = _end = -1; // only for flows
    adj.resize(n);
    imb.resize(n);
  }
  // Adds an arc to the graph. u is capacity, c is cost.
  // u is only needed on flows, and c only on min-cost-flow
  int arc(int i, int j, int u = 0, double c = 0) {
    dest.pb(j);
    adj[i].pb(sz(dest)-1);
    dest.pb(i);
    adj[j].pb(sz(dest)-1);
    cap.pb(u); // For both flows
    cap.pb(0);
    cost.pb(c); // Only for min cost flow
    cost.pb(-c);
    return sz(dest)-2;
  }
  //////////////////////////////////////////////////////////////////////////////
  // For both flows!!
  //

  vi cap, flow;
  int _ini, _end;   // ini, end of last maxflow

  int orig(int a) { return dest[inv(a)]; }
  int capres(int a) { return cap[a] - flow[a]; }

  //////////////////////////////////////////////////////////////////////////////
  // Max Flow! - Dinic O(n^2 * m) incremental
  // don't call maxflow with ini == end
  //

  vi d, curAdj;

  bool MFbfs(int s, int t) {
    d = vi(sz(adj), INF);
    curAdj = vi(sz(adj));
    d[s] = 0;
    queue<int> Q; Q.push(s);
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (auto i : adj[u]) {
        int v = dest[i];
        if (capres(i) > 0 && d[v] == INF) {
          d[v] = d[u] + 1; Q.push(v);
        }
      }
    }
    return d[t] != INF;
  }

  int MFdfs(int u, int t, int f) {
    if (u == t) return f;
    for(int &i = curAdj[u]; i < adj[u].size(); ++i) {
      int ar = adj[u][i], v = dest[ar];
      if (d[v] != d[u]+1 || capres(ar) == 0) continue;
      int tmpF = MFdfs(v, t, min(f, capres(ar)));
      if (tmpF) {
        flow[ar] += tmpF;
        flow[inv(ar)] -= tmpF;
        return tmpF;
      }
    }
    return 0;
  }

  int maxflow(int ini, int end) {
    if (_ini != ini || _end != end) {
      flow = vi(sz(dest));
      _ini = ini;
      _end = end;
    }
    while (MFbfs(ini, end))
      while (MFdfs(ini, end, INF));
    int F = 0;
		for (int a : adj[ini]) F += flow[a];
    return F;
  }


  //////////////////////////////////////////////////////////////////////////////
  // Min Cost Flow! - O(m^2 * log n * log U) incremental
  // Don't forget to specify the [imb]
  // look at [imb] for feasibility
  //

  vi imb;
  vd cost, pot;
  int delta;

  double rescost(int a) {
    return cost[a] + pot[orig(a)] - pot[dest[a]];
  }

  bool dijkstra() {
    priority_queue<pair<double, pair<int, int> > > q;
    vi ent(sz(adj), -2);
    vd dist(sz(adj), INF);
    fu(u, sz(adj)) if (imb[u] >= delta)
      q.push(make_pair(0.0, make_pair(u, -1)));

    while (!q.empty()) {
      int u = q.top().second.first, f = q.top().second.second;
      double d = -q.top().first; q.pop();
      if (ent[u] != -2) continue; dist[u] = d; ent[u] = f;
			for (int a : adj[u]) if (capres(a) >= delta)
        q.push(make_pair(-(dist[u] + rescost(a)), make_pair(dest[a], a)));
    }

    fu(u, sz(adj)) if (ent[u] != -2 && imb[u] <= -delta) {
      fu(v, sz(adj)) pot[v] += dist[v];
      for (int a = ent[u]; a != -1; a = ent[orig(a)]) {
        flow[a] += delta;
        flow[inv(a)] -= delta;
        imb[dest[a]] += delta;
        imb[orig(a)] -= delta;
      }
      return true;
    }
    return false;
  }

  double mincostflow() {
    pot.resize(sz(adj));
    flow.resize(sz(dest));
    for (delta = 0x40000000; delta > 0; delta /= 2) {
      fu(a, sz(dest)) {
        int u = orig(a), v = dest[a];
        if (capres(a) >= delta && cmp(rescost(a)) < 0) {
          imb[u] -= capres(a);
          imb[v] += capres(a);
          flow[inv(a)] -= capres(a);
          flow[a] += capres(a);
        }
      }
      while (dijkstra());
    }
    double C = 0.0;
    fu(a, sz(dest)) if (flow[a] > 0) C += flow[a] * cost[a];
    return C;
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    cin >> N >> X >> Y;
    X--, Y--;

    graph g(2 * N + 2);

    vi rev(N);
    for (int i = 0; i < N; i++) {
        cin >> rev[i];
    }

    array<vvi, 2> trees;
    for (int t = 0; t < 2; t++) {
        trees[t].resize(N);
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            trees[t][u-1].push_back(v-1);
            trees[t][v-1].push_back(u-1);
        }
    }

    array<vi, 2> demands;
    for (int t = 0; t < 2; t++) {
        demands[t].resize(N, -1);
        int Q, v, d;
        cin >> Q;
        for (int q = 0; q < Q; q++) {
            cin >> v >> d;
            demands[t][v-1] = d;
        }
    }

    array<vi, 2> assign;
    assign[0].resize(N, -1);
    assign[1].resize(N, -1);

    bool failed = false;
    function<int(vvi&, vi&, vi&, int, int, int)> calc = [&](vvi& tree, vi& demands, vi& assig, int loc, int par, int abv) {
        if (demands[loc] != -1) abv = loc;
        assig[loc] = abv;

        int res = 0;
        for (int ch : tree[loc]) {
            if (ch == par) continue;
            res += calc(tree, demands, assig, ch, loc, abv);
        }
        if (demands[loc] != -1) {
            int tmp = demands[loc];
            demands[loc] -= res;
            if (demands[loc] < 0)
                failed = true;
            res = tmp;
        }
        return res;
    };

    if (demands[0][X] != demands[1][Y]) {
        cout << -1 << endl;
        return 0;
    }

    g.imb[0] = demands[0][X];
    g.imb[2 * N + 1] = -demands[1][Y];

    calc(trees[0], demands[0], assign[0], X, X, X);
    calc(trees[1], demands[1], assign[1], Y, Y, Y);
    if (failed) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        g.arc(assign[0][i] + 1, assign[1][i] + N + 1, 1, -rev[i]);
    }
    for (int i = 0; i < N; i++) {
        g.arc(0, 1 + i, demands[0][i], 0);
        g.arc(1 + N + i, 2 * N + 1, demands[1][i], 0);
    }

    int revenue = -g.mincostflow() + 0.5;
    for (int v : g.imb) if (v != 0) revenue = -1;
    cout << revenue << endl;

    return 0;
}