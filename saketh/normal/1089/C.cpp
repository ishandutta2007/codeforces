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
using vb = vector<bool>;
using vs = vector<string>;

void go(int N, vvi& dist) {
    vi pos(N);
    for (int i = 0; i < N; i++)
        pos[i] = i;

    string resp;
    while (pos.size() > 1) {
        int guess = -1, best = INT_MAX;
        for (int g = 0; g < N; g++) {
            int totd = 0;
            for (int v : pos)
                totd += dist[g][v];

            if (totd < best) {
                best = totd;
                guess = g;
            }
        }

        cout << guess + 1 << endl;
        cin >> resp;

        if (resp == "FOUND") return;

        int u;
        cin >> u;
        u--;

        vi rem;
        for (int v : pos) {
            if (dist[u][v] < dist[guess][v])
                rem.push_back(v);
        }
        pos = rem;
    }

    cout << pos.back() + 1 << endl;
    cin >> resp;
    assert(resp == "FOUND");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vvi dist(N, vi(N, INT_MAX/2));

    for (int i = 0; i < M; i++) {
        int P;
        cin >> P;
        vi path(P);
        for (int j = 0; j < P; j++) {
            cin >> path[j];
            --path[j];
            if (j) {
                dist[path[j-1]][path[j]] = 1;
                dist[path[j]][path[j-1]] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int r = 0; r < N; r++) {
        go(N, dist);
    }

    return 0;
}