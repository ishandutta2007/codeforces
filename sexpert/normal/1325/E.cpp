#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 1
// p
// p^2
// pq, p^3
// p^4
// p^5 pq^2
// p^6
// no sq ->
// p, pq, p^3, p^5, pq^2
// simplify to
// p, pq

const int MAXV = 1e6 + 5;
int pr[MAXV], red[MAXV], dis[MAXV], par[MAXV], res = MAXV;
vector<int> adj[MAXV];

void bfs(int s) {
    memset(dis, -1, sizeof dis);
    memset(par, -1, sizeof par);
    dis[s] = 0;
    int ans = MAXV;
    queue<int> q({s});
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(v != par[u] && dis[v] != -1)
                ans = min(ans, dis[u] + dis[v] + 1);
            if(dis[v] == -1) {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
 
    res = min(res, ans);
}

void sieve() {
    for(int p = 2; p < MAXV; p++) {
        if(pr[p])
            continue;
        for(int q = p; q < MAXV; q += p)
            pr[q] = p;
    }
}

int uwu(int n) {
    int res = 1;
    while(n > 1) {
        int p = pr[n];
        ll sq = (ll)p * p;
        while(n % sq == 0)
            n /= sq;
        if(n % p)
            continue;
        res *= p;
        n /= p;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    for(int i = 1; i < MAXV; i++)
        red[i] = uwu(i);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
        x = red[x];
    }
    for(auto x : v) {
        if(x == 1) {
            cout << "1\n";
            return 0;
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.size() < n) {
        cout << "2\n";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        int x = v[i];
        if(x == pr[x]) {
            adj[MAXV - 1].push_back(x);
            adj[x].push_back(MAXV - 1);
        }
        else {
            int p = pr[x], q = x / pr[x];
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
    }
    bfs(MAXV - 1);
    for(int p = 2; p <= 1000; p++) {
        if(pr[p] == p)
            bfs(p);
    }
    cout << (res == MAXV ? -1 : res) << '\n';
}