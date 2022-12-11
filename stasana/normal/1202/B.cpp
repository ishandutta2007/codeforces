#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int64_t ll;
typedef long double ld;

const int INF = (int)(1e9) + 666;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    string s;
    cin >> s;
    vector<vector<int>> cnt(10, vector<int>(10));
    for (int i = 0; i + 1 < (int)s.length(); ++i) {
        ++cnt[s[i] - '0'][s[i + 1] - '0'];
    }
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            ll result = 0;
            for (int z = 0; z < 10; ++z) {
                queue<int> q;
                vector<int> dist(10, INF);
                dist[(z + x) % 10] = 0;
                dist[(z + y) % 10] = 0;
                q.push((z + x) % 10);
                q.push((z + y) % 10);
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    int u = (v + x) % 10;
                    if (dist[u] > dist[v] + 1) {
                        dist[u] = dist[v] + 1;
                        q.push(u);
                    }
                    u = (v + y) % 10;
                    if (dist[u] > dist[v] + 1) {
                        dist[u] = dist[v] + 1;
                        q.push(u);
                    }
                }
                for (int i = 0; i < 10; ++i) {
                    if (cnt[z][i]) {
                        if (dist[i] == INF) {
                            result = -1;
                            break;
                        }
                    }
                    result += dist[i] * cnt[z][i];
                }
                if (result == -1) {
                    break;
                }
            }
            cout << result << " ";
        }
        cout << "\n";
    }
}

int main() {
    start();
    solve();
    return 0;
}