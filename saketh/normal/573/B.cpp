#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 100;

int N, tall[MAXN];
vector<pair<int, int>> adj[MAXN];

int dist[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tall[i];

        adj[0].emplace_back(i+1, tall[i]);
        adj[i].emplace_back(i+1, 1);
        if(i+1 < N) adj[i+2].emplace_back(i+1, 1);
        else adj[0].emplace_back(i+1, 1);
    }

    memset(dist, 0x7f, sizeof(dist));
    dist[0] = 0;

    priority_queue<pair<int, int>> dij;
    dij.push({0, 0});

    while(!dij.empty()){
        int cost = -dij.top().first;
        int loc = dij.top().second;
        dij.pop();

        if(cost > dist[loc]) continue;

        for (auto p : adj[loc]) {
            int nbr = p.first;
            int get = cost + p.second;

            if(get < dist[nbr]) {
                dist[nbr] = get;
                dij.push({-get, nbr});
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;
}