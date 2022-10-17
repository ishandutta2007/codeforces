#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M, K, W;
char level[1024][10][10];
int dist[1024][1024];

int comp(int i, int j) {
    int diff = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (level[i][r][c] != level[j][r][c]) {
                diff++;
            }
        }
    }

    if (i > 0 && j > 0) diff *= W;
    return diff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> K >> W;

    for (int i = 0; i <= K; i++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (i == 0) level[i][r][c] = '!';
                else cin >> level[i][r][c];
            }
        }
    }

    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++)
            dist[i][j] = comp(i, j);

    vector<bool> got(K + 1);
    priority_queue<tuple<int, int, int>> pq;
    pq.push(make_tuple(0, 0, -1));

    int ans = 0;
    vector<pair<int, int>> seq;

    while (pq.size()) {
        int cost = -get<0>(pq.top());
        int which = get<1>(pq.top());
        int prev = get<2>(pq.top());

        pq.pop();
        if (got[which]) continue;

        ans += cost;
        got[which] = true;
        if (prev != -1) seq.emplace_back(which, prev);

        for (int i = 0; i <= K; i++) {
            if (got[i]) continue;
            pq.push(make_tuple(-dist[which][i], i, which));
        }
    }

    cout << ans << "\n";
    for (auto p : seq)
        cout << p.first << " " << p.second << "\n";
}