#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef array<int, 3> bulb;
typedef vector<bulb> garland;

bool in(vector<array<int, 4>> &queries, int q, bulb coord) {
    int x = coord[0], y = coord[1];
    return queries[q][0] <= x && x <= queries[q][2]
        && queries[q][1] <= y && y <= queries[q][3];
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    vector<garland> garl(K);

    for (int g = 0; g < K; g++) {
        int C;
        scanf("%d", &C);

        for (int i = 0; i < C; i++) {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            garl[g].push_back({x, y, w});
        }
    }

    int bbao = 0;
    vector<array<int, 4>> query;
    vector<vector<bool>> state;
    vector<vector<int>> horiz(N + 1), vert(M + 1);

    int Q;
    scanf("%d", &Q);
    vector<bool> lit(K, true);

    for (int q = 0; q < Q; q++) {
        char string[256];
        scanf(" %s", string);

        if (string[0] == 'S') {
            int inx;
            scanf("%d", &inx);
            lit[inx - 1] = !lit[inx - 1];
        } else {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            query.push_back({ x1, y1, x2, y2 });

            horiz[x1 - 1].push_back(bbao);
            horiz[x2].push_back(bbao);
            vert[y1 - 1].push_back(bbao);
            vert[y2].push_back(bbao);

            state.resize(state.size() + 1);
            state[bbao] = lit;
            bbao++;
        }
    }

    Q = bbao;
    vector<ll> ans(Q);

    for (int g = 0; g < K; g++) {
        int S = garl[g].size();
        vector<ll> pref(S + 1);
        for (int i = 1; i <= S; i++)
            pref[i] = pref[i-1] + garl[g][i-1][2];

        vector<int> ent(Q, -1);
        for (int q = 0; q < Q; q++)
            if (in(query, q, garl[g].front()))
                ent[q] = 0;

        for (int i = 1; i < S; i++) {
            vector<int> check;
            if (garl[g][i][0] == garl[g][i-1][0]) {
                int col = min(garl[g][i][1], garl[g][i-1][1]);
                for (int q : vert[col])
                    check.push_back(q);
            } else {
                int row = min(garl[g][i][0], garl[g][i-1][0]);
                for (int q : horiz[row])
                    check.push_back(q);
            }

            for (int q : check) {
                bool now = in(query, q, garl[g][i]);
                bool bef = in(query, q, garl[g][i-1]);

                if (now == bef) continue;

                if (now) {
                    ent[q] = i;
                } else {
                    if (state[q][g])
                        ans[q] += pref[i] - pref[ent[q]];
                    ent[q] = -1;
                }
            }
        }

        for (int q = 0; q < Q; q++) 
            if (in(query, q, garl[g].back()) && state[q][g])
                ans[q] += pref.back() - pref[ent[q]];
    }

    for (int i = 0; i < Q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}