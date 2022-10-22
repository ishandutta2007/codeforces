#include <bits/stdc++.h>
using namespace std;

const int N = 10005, INF = (int)1e9;
typedef pair<int, int> P;

int n, m, k;
int x[N], y[N];
int dis[N];


int main() {
    cin >> n >> m >> k;
    int ed = -1;
    int st = -1;
    for(int i = 0; i < k; i++) {
        cin >> x[i] >> y[i]; x[i]--, y[i]--;
        if(x[i] == n - 1 && y[i] == m - 1) ed = i;
        if(x[i] == 0 && y[i] == 0) st = i;
    }

    if(ed == -1) x[k] = n - 1, y[k] = m - 1, k++;

    fill(dis, dis + N, INF);
    deque<P> que;
    que.push_back({0, st});
    dis[st] = 0;
    while(!que.empty()) {
        auto p = que.front(); que.pop_front();
        int dist = p.first, v = p.second;
        if(dist > dis[v]) continue;
        for(int nxt = 0; nxt < k; nxt++) {
            if(abs(x[nxt] - x[v]) + abs(y[nxt] - y[v]) == 1 && !(ed == -1 && nxt == k - 1)) {
                if(dis[v] < dis[nxt]) {
                    dis[nxt] = dis[v];
                    que.push_front({dis[nxt], nxt});
                }
            }
            else if(abs(x[nxt] - x[v]) <= 1 || abs(y[nxt] - y[v]) <= 1 ||
            ((abs(x[nxt] - x[v]) == 2 || abs(y[nxt] - y[v]) == 2) && !(ed == -1 && nxt == k - 1))) {
                if(dis[v] + 1 < dis[nxt]) {
                    dis[nxt] = dis[v] + 1;
                    que.push_back({dis[nxt], nxt});
                }
            }
        }
    }
    if(ed == -1) ed = k - 1;
    cout << (dis[ed] == INF ? -1 : dis[ed]) << endl;
}