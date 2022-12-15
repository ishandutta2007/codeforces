#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 3;
const int Inf = 1e9;
const int Log = 20;
const ll Mod = 998244353;

int n, m;
vector<int> adj[2][N];
int dist2[Log][N];
pair<int, int> dist[2][N];

int solve2(){
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < Log; ++j)
            dist2[j][i] = Inf;

    deque<array<int, 2>> dq;
    dq.push_back({0, 1});
    dist2[0][1] = 0;

    int ans = Inf;
    while(!dq.empty()){
        array<int, 2> node = dq.front();
        dq.pop_front();

        if(node[1] == n){
            int curr = dist2[node[0]][node[1]];
            if(node[0]) curr += (1 << node[0]) - 1;
            ans = min(ans, curr);
        }

        for(int to: adj[node[0] & 1][node[1]]){
            if(dist2[node[0]][node[1]] + 1 < dist2[node[0]][to]){
                dist2[node[0]][to] = dist2[node[0]][node[1]] + 1;
                dq.push_back({node[0], to});
            }
        }

        if(node[0] < Log - 1 && dist2[node[0]][node[1]] < dist2[node[0] + 1][node[1]]){
            dist2[node[0] + 1][node[1]] = dist2[node[0]][node[1]];
            dq.push_back({node[0] + 1, node[1]});
        }
    }

    return ans;
}

ll fast_pow(ll base, ll exp){
    if(!exp) return 1;
    if(exp & 1) return fast_pow(base, exp ^ 1) * base % Mod;

    ll t = fast_pow(base, exp >> 1);
    return t * t % Mod;
}

pair<int, int> solve(){
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 2; ++j)
            dist[j][i] = {Inf, Inf};

    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
    pq.push({0, 0, 0, 1});
    dist[0][1] = {0, 0};

    pair<int, int> ans{Inf, Inf};
    while(!pq.empty()){
        auto [d1, d2, nd1, nd2] = pq.top();
        pq.pop();

        if(dist[nd1][nd2] != pair{d1, d2}) continue;
        if(nd2 == n) ans = min(ans, {d1, d2});

        for(int to: adj[nd1][nd2]){
            if(dist[nd1][to] > pair{d1, d2 + 1}){
                dist[nd1][to] = {d1, d2 + 1};
                pq.push({d1, d2 + 1, nd1, to});
            }
        }

        if(dist[!nd1][nd2] > pair{d1 + 1, d2}){
            dist[!nd1][nd2] = {d1 + 1, d2};
            pq.push({d1 + 1, d2, !nd1, nd2});
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }

    pair<int, int> t = solve();
    if(t.first >= Log){
        ll ans = fast_pow(2, t.first) - 1 + t.second;
        ans %= Mod;
        if(ans < 0) ans += Mod;
        cout << ans << "\n";
        return 0;
    }

    cout << solve2() << "\n";
}