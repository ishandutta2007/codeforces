#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
char grid[1024][1024];

int ind[1024][1024];
vector<pair<int, int>> adj[1024][1024];

int lch[1024][1024];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
string targ = "DIMA";

bool succ(char a, char b) {
    int i = targ.find(a);
    int j = targ.find(b);
    return (i + 1) % 4 == j;
}

bool in(int i, int j) {
    if (i < 0 || j < 0) return false;
    if (i >= N || j >= M) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (!in(ni, nj)) continue;
                if (!succ(grid[i][j], grid[ni][nj])) continue;

                adj[i][j].push_back(make_pair(ni, nj));
                ind[ni][nj]++;
            }
        }
    }

    vector<pair<int, int>> topo;
    queue<pair<int, int>> zero;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ind[i][j] == 0) {
                zero.push(make_pair(i, j));
            }
        }
    }

    while (!zero.empty()) {
        pair<int, int> loc = zero.front();
        zero.pop();
        topo.push_back(loc);

        for (auto p : adj[loc.first][loc.second]) {
            if (--ind[p.first][p.second] == 0) {
                zero.push(p);
            }
        }
    }

    if (topo.size() != N * M) { cout << "Poor Inna!\n"; return 0; }

    int ans = 0;

    reverse(topo.begin(), topo.end());

    for (auto p : topo) {
        int i = p.first, j = p.second;
        lch[i][j] = 1;

        for (auto p2 : adj[p.first][p.second]) {
            lch[i][j] = max(lch[i][j], 1 + lch[p2.first][p2.second]);
        }

        if (grid[i][j] == 'D') ans = max(ans, lch[i][j]);
    }

    if (ans < 4) cout << "Poor Dima!\n";
    else cout << ans / 4 << "\n";
}