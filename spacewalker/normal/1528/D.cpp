#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
constexpr int NMAX = 610;

int pwdist[NMAX][NMAX];
int sReach[NMAX][NMAX];
int n;

int jumpDist(int i, int j, int t) {
    t %= n;
    return sReach[i][(j - t + n) % n];
}

int main() {
    int m; scanf("%d %d", &n, &m);
    memset(sReach, 0x3f, sizeof sReach);
    for (int i = 0; i < m; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        sReach[a][b] = min(sReach[a][b], c);
        for (int offset = 1; offset < n; ++offset) {
            int cb = (b + offset) % n;
            sReach[a][cb] = min(sReach[a][cb], sReach[a][b] + offset);
        }
    }
    memset(pwdist, 0x3f, sizeof pwdist);
    for (int st = 0; st < n; ++st) {
        pwdist[st][st] = 0;
        vector<bool> proc(n);
        for (int iter = 0; iter < n; ++iter) {
            int toVis = -1;
            for (int i = 0; i < n; ++i) if (!proc[i] && (toVis == -1 || pwdist[st][toVis] > pwdist[st][i])) toVis = i;
            proc[toVis] = true;
            for (int nxt = 0; nxt < n; ++nxt) {
                int d2n = pwdist[st][toVis] + jumpDist(toVis, nxt, pwdist[st][toVis]);
                if (d2n < pwdist[st][nxt]) pwdist[st][nxt] = d2n;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", pwdist[i][j]);
        printf("\n");
    }
}