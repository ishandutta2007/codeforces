#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

const int INF = INT_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<int> deg(N);

    for (int i = 0; i < N; i++)
        dist[i][i] = 0;

    int u, v;
    for (int e = 0; e < M; e++) {
        cin >> u >> v;
        u--, v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
        deg[u]++, deg[v]++;
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < N; i++) {
        WATCHC(dist[i]);
    }

    double ans = 0;

    for (int s = 0; s < N; s++) {
        WATCH(s);
        double res = 0;

        vector<vector<int>> at_dist(N);
        for (int i = 0; i < N; i++)
            at_dist[dist[s][i]].push_back(i);

        for (int d = 0; d < N; d++) {
            vector<int> &cand = at_dist[d];
            if (!cand.size()) continue;

            vector<int> move;
            vector<double> chance(N);

            WATCHC(cand);

            for (int l : cand) {
                for (int nbr = 0; nbr < N; nbr++) {
                    if (dist[l][nbr] == 1) {
                        move.push_back(nbr);
                        chance[nbr] += 1.0 / deg[l] / cand.size();
                    }
                }
            }

            sort(move.begin(), move.end());
            move.erase(unique(move.begin(), move.end()), move.end());

            WATCHC(chance);

            double succ = 0;

            vector<double> likeliest(N);

            for (int t = 0; t < N; t++) {
                double right = 0;
                for (int e : move) {
                    int d2 = dist[t][e];
                    right -= likeliest[d2];
                    likeliest[d2] = max(likeliest[d2], chance[e]);
                    right += likeliest[d2];
                }

                succ = max(succ, right);

                for (int e : move) {
                    int d2 = dist[t][e];
                    likeliest[d2] = 0;
                }
            }

            double prob = cand.size() / double(N);
            res += prob * max(succ, 1.0 / cand.size());
        }

        WATCH(res);
        ans = max(ans, res);
    }

    cout << ans << endl;
    return 0;
}