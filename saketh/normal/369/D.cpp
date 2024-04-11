#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3100;
const int INF = 0x7f7f7f7f;

int N, K;
int ch[MAXN];

int dist[MAXN][MAXN];
int big[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> ch[i];
    }

    for (int i = N - 2; i >= 0; i--) {
        big[i] = max(big[i+1], ch[i+1]);
    }

    memset(dist, 0x7f, sizeof(dist));
    dist[0][0] = 0;

    queue<pair<int, int>> bfs;
    bfs.push({0, 0});

    int ans = 0;

    while (!bfs.empty()) {
        int i = bfs.front().first;
        int d = bfs.front().second;
        int r = dist[i][d];

        bfs.pop();
        ans++;

        if (i < N && d < (N - i - 1) && r < K) {
            int j = i + d + 1;

            // i dies 
            if (big[j-1] > 0 && ch[i] < 100) {
                if (dist[j][0] == INF) {
                    dist[j][0] = r + 1;
                    bfs.push({j, 0});
                }
            }
            // j dies
            if (big[i] < 100 && ch[i] > 0) {
                if (dist[i][d+1] == INF) {
                    dist[i][d+1] = r + 1;
                    bfs.push({i, d+1});
                }
            }
            // both die
            if (big[j-1] > 0 && ch[i] > 0) {
                if (dist[j+1][0] == INF) {
                    dist[j+1][0] = r + 1;
                    bfs.push({j+1, 0});
                }
            }
        }
    }

    cout << ans << "\n";
}