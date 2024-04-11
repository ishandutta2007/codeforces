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

vvi dist;
void init_debug(int N) {
    dist.resize(N, vi(N, INT_MAX/2));
    for (int i = 0; i < N; i++)
        dist[i][i] = 0;

    for (int e = 0; e < N - 1; e++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dist[u][v] = dist[v][u] = 1;
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int query(vi S, vi T, int v) {
    int res = 0;

    TRACE({
        for (int a : S)
            for (int b : T)
                if (dist[a][b] == dist[a][v] + dist[v][b])
                    res++;
        return res;
    })

    cout << S.size() << "\n";
    for (int u : S)
        cout << u + 1 << " ";
    cout << "\n";
    cout << T.size() << "\n";
    for (int u : T)
        cout << u + 1 << " ";
    cout << "\n";
    cout << v + 1 << endl;

    cin >> res;
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    TRACE(init_debug(N));

    vi que;
    for (int j = 1; j < N; j++)
        que.push_back(j);
    vi subt(N);
    subt[0] = N;
    for (int i = 1; i < N; i++) {
        subt[i] = query({0}, que, i);
    }

    que.push_back(0);
    sort(all(que), [&subt](int i, int j) {
        return subt[i] < subt[j];
    });

    for (auto row : dist) {
        WATCHC(row);
    }
    WATCHC(subt);
    WATCHC(que);

    vector<pair<int, int>> edges;
    vi nopar;
    for (int u : que) {
        vi pref(nopar.size() + 1, -1);
        pref[0] = 0;
        if (nopar.size())
            pref.back() = query({0}, nopar, u);

        function<void(int, int)> calc_pref = [&](int i, int j) {
            if (i + 1 >= j) return;
            if (pref[i] == pref[j]) {
                for (int k = i + 1; k < j; k++)
                    pref[k] = pref[i];
                return;
            }
            if (pref[j] - pref[i] == j - i) {
                for (int k = i + 1; k < j; k++)
                    pref[k] = pref[i] + k - i;
                return;
            }

            int mi = (i + j) / 2;
            vi check(nopar.begin(), nopar.begin() + mi);
            pref[mi] = query({0}, check, u);

            calc_pref(i, mi);
            calc_pref(mi, j);
        };
        calc_pref(0, pref.size() - 1);

        vi stillnopar;
        for (int i = 0; i < nopar.size(); i++) {
            if (pref[i] != pref[i+1])
                edges.emplace_back(nopar[i], u);
            else stillnopar.push_back(nopar[i]);
        }

        swap(nopar, stillnopar);
        nopar.push_back(u);
    }

    cout << "ANSWER\n";
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << "\n";
    }

    return 0;
}