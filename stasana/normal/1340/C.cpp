// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <set>

using namespace std;

typedef int ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

const ll INF = (ll)2e9 + 666;

ll n, m;
ll g, r;
vector<ll> d;
ll dist[10'000][1'000];
bitset<10'000'000> used;

inline void solve() {
    cin >> n >> m;
    d.resize(m);
    for (ll i = 0; i < m; ++i) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    cin >> g >> r;
    for (ll x = 0; x < m; ++x) {
        for (ll y = 0; y < g; ++y) {
            dist[x][y] = INF;
        }
    }
    dist[0][0] = 0;
    queue<pair<ll, ll>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        used[x * g + y] = false;
        q.pop();
        if (x != 0) {
            int new_y = y + d[x] - d[x - 1];
            if (new_y <= g) {
                int new_time = dist[x][y] + d[x] - d[x - 1];
                if (new_y == g) {
                    new_time += r;
                    new_y = 0;
                }
                if (dist[x - 1][new_y] > new_time) {
                    dist[x - 1][new_y] = new_time;
                    if (!used[(x - 1) * g + new_y]) {
                        used[(x - 1) * g + new_y] = true;
                        q.push(make_pair(x - 1, new_y));
                    }
                }
            }
        }
        if (x != m - 1) {
            int new_y = y + d[x + 1] - d[x];
            if (new_y <= g) {
                int new_time = dist[x][y] + d[x + 1] - d[x];
                if (new_y == g) {
                    new_time += r;
                    new_y = 0;
                }
                if (dist[x + 1][new_y] > new_time) {
                    dist[x + 1][new_y] = new_time;
                    if (!used[(x + 1) * g + new_y]) {
                        used[(x + 1) * g + new_y] = true;
                        q.push(make_pair(x + 1, new_y));
                    }
                }
            }
        }
    }
    int mn;
    if (dist[m - 1][0] != INF) {
        mn = dist[m - 1][0] - r;
    } else {
        mn = INF;
    }
    for (int i = 1; i < g; ++i) {
        mn = min(mn, dist[m - 1][i]);
    }
    if (mn == INF) {
        cout << -1 << endl;
        return;
    }
    cout << mn << endl;
}

int main() {
    start();
    solve();
    return 0;
}