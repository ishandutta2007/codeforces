#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vvi adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vi deg(N), wt(N, 1), leaf;
    for (int i = 0; i < N; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1)
            leaf.push_back(i);
    }

    ll ans = 0;

    for (int i = 0; i < leaf.size(); i++) {
        int l = leaf[i];
        int nbr = -1;
        for (int v : adj[l]) {
            if (wt[v]) {
                nbr = v;
                break;
            }
        }

        if (nbr == -1) {
            // it's a tree
            cout << ans / 2 << endl;
            return 0;
        }

        ans += wt[l] * 2ll * (N - wt[l]);
        wt[nbr] += wt[l];
        wt[l] = 0;
        --deg[l];
        if (--deg[nbr] == 1)
            leaf.push_back(nbr);
    }

    vi spec;
    for (int i = 0; i < N; i++) {
        if (deg[i] > 2)
            spec.push_back(i);
    }
    if (spec.empty()) {
        for (int i = 0; i < N; i++) {
            if (deg[i] == 2) {
                spec.push_back(i);
                break;
            }
        }
    }

    const int S = spec.size();
    vb is_spec(N);
    for (int v : spec) is_spec[v] = true;

    vvi dist(spec.size(), vi(N, INT_MAX));
    for (int i = 0; i < S; i++) {
        dist[i][spec[i]] = 0;
        vi bfs({ spec[i] });
        for (int j = 0; j < bfs.size(); j++) {
            int v = bfs[j];
            for (int u : adj[v]) {
                if (dist[i][u] != INT_MAX) continue;
                dist[i][u] = dist[i][v] + 1;
                bfs.push_back(u);
            }
        }
    }

    vi pid(N, -1), ps, pt;
    vvi paths;
    for (int v : spec) {
        for (int x : adj[v]) {
            if (!wt[x] || is_spec[x] || pid[x] != -1) continue;

            vi p;
            for (int par = v; !is_spec[x]; ) {
                p.push_back(x);
                int ns = 0;
                for (int n : adj[x])
                    if (wt[n]) ns += n;
                int nn = ns - par;
                par = x;
                x = nn;
            }

            for (int v : p) pid[v] = paths.size();
            ps.push_back(lower_bound(all(spec), v) - spec.begin());
            pt.push_back(lower_bound(all(spec), x) - spec.begin());
            paths.push_back(p);
        }
    }

    const int P = paths.size();
    vvll pref(P), suff(P), mbeg(P), mend(P);
    for (int z = 0; z < paths.size(); z++) {
        const vi& p = paths[z];

        pref[z].resize(p.size());
        for (int i = 0; i < p.size(); i++)
            pref[z][i] = wt[p[i]] + (i ? pref[z][i-1] : 0);

        suff[z].resize(p.size());
        for (int i = p.size() - 1; i >= 0; i--)
            suff[z][i] = wt[p[i]] + (i+1 < p.size() ? suff[z][i+1] : 0);

        mbeg[z].resize(p.size());
        for (int i = 0; i < p.size(); i++)
            mbeg[z][i] = (i + 1) * wt[p[i]] + (i ? mbeg[z][i-1] : 0);

        mend[z].resize(p.size());
        for (int i = p.size() - 1; i >= 0; i--)
            mend[z][i] = (p.size() - i) * wt[p[i]] + (i+1 < p.size() ? mend[z][i+1] : 0);
    }

    auto calc_range = [&](int z, int i, int j, int sd, int td, int m) {
        int elt = j - i + 1;

        int jlim = td - sd + elt;
        if (jlim > 0) jlim = (jlim + 1) / 2;
        else jlim = 0;
        jlim = min(jlim, elt);

        if (jlim > 0) {
            ll ltot = pref[z][i+jlim-1] - (i ? pref[z][i-1] : 0);
            ans += ltot * m * sd;

            ll linc = mbeg[z][i+jlim-1] - (i ? mbeg[z][i-1] : 0);
            linc -= i * ltot;
            ans += m * linc;
        }
        if (jlim < elt) {
            ll rtot = suff[z][i+jlim] - (j+1 < paths[z].size() ? suff[z][j+1] : 0);
            ans += rtot * m * td;

            ll rinc = mend[z][i+jlim] - (j + 1 < paths[z].size() ? mend[z][j+1] : 0);
            rinc -= (paths[z].size() - j - 1) * rtot;
            ans += m * rinc;
        }
    };

    for (int z = 0; z < paths.size(); z++) {
        const vi& p = paths[z];
        for (int i = 0; i < p.size(); i++) {
            if (i) calc_range(z, 0, i-1, dist[ps[z]][p[i]], 0, wt[p[i]]);
            if (i+1 < p.size()) calc_range(z, i+1, p.size() - 1, 0, dist[pt[z]][p[i]], wt[p[i]]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (wt[i] == 0) continue;

        for (int s = 0; s < spec.size(); s++) {
            ans += dist[s][i] * 1ll * wt[i] * wt[spec[s]];
        }

        for (int z = 0; z < paths.size(); z++) {
            if (pid[i] == z) continue;
            int s = ps[z], t = pt[z];
            calc_range(z, 0, paths[z].size() - 1, dist[s][i], dist[t][i], wt[i]);
        }
    }

    cout << ans / 2 << endl;
    return 0;
}