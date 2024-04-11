#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

const int MAXN = 100500;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

typedef pair< ll, int > pli;
set< pli > rails, q;
vector< ll > dist;
vector< vector< pli > > g;
int n, m, k;
vector< ll > min_rail;
bool used[MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    min_rail.assign(n + 5, INF);
    dist.assign(n + 5, INF);
    g.clear();
    g.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        used[i] = false;
    }
    for (int i = 1; i <= m; ++i) {
        int from, to;
        ll len;
        cin >> from >> to >> len;
        g[from].push_back(make_pair(len, to));
        g[to].push_back(make_pair(len, from));
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        int s;
        ll len;
        cin >> s >> len;
        if (min_rail[s] != INF) {
            ++ans;
        }
        min_rail[s] = min(min_rail[s], len);
    }
    rails.clear();
    q.clear();
    for (int i = 1; i <= n; ++i) {
        if (min_rail[i] != INF) {
            rails.insert(make_pair(min_rail[i], i));
        }
    }
    q.insert(make_pair(0, 1));
    while (!q.empty() || !rails.empty()) {
        pli cur_p;
        if (q.empty()) {
            cur_p = *(rails.begin());
            rails.erase(cur_p);
            if (used[cur_p.second]) {
                ++ans;
            }
        } else {
            if (rails.empty()) {
                cur_p = *(q.begin());
                q.erase(cur_p);
            } else {
                pli q_p = *(q.begin()), rails_p = *(rails.begin());
                if (q_p.first <= rails_p.first) {
                    cur_p = q_p;
                    q.erase(cur_p);
                } else {
                    cur_p = rails_p;
                    rails.erase(cur_p);
                    if (used[cur_p.second]) {
                        ++ans;
                    }
                }
            }
        }
        if (used[cur_p.second]) {
            continue;
        }
        int cur = cur_p.second;
        ll cur_len = cur_p.first;
        used[cur] = true;
        dist[cur] = cur_len;
        for (vector< pli >::iterator it = g[cur].begin(); it != g[cur].end(); ++it) {
            int to = it->second;
            ll a_len = cur_len + it->first;
            if (a_len < dist[to]) {
                q.erase(make_pair(dist[to], to));
                dist[to] = a_len;
                q.insert(make_pair(dist[to], to));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}