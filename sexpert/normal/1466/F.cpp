#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;
const ll MOD = 1e9 + 7;
int rep[MAXN], sz[MAXN], di[MAXN], cnt[MAXN];
ll p2[MAXN];
vector<int> adj[MAXN];
vector<array<int, 2>> edges;
vector<int> chosen;

int find(int u) {
    return rep[u] == 0 ? u : find(rep[u]);
}

int col(int u) {
    return rep[u] == 0 ? 0 : di[u] ^ col(rep[u]);
}

bool join(int u, int v) {
    int x = col(u), y = col(v);
    u = find(u); v = find(v);
    if(u == v)
        return false;
    if(sz[u] < sz[v])
        swap(u, v);
    rep[v] = u;
    sz[u] += sz[v];
    cnt[u] += cnt[v];
    cnt[u]++;
    di[v] = y ^ x ^ 1;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p2[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p2[i] = (2LL * p2[i - 1]) % MOD;

    int n, m;
    cin >> n >> m;
    vector<int> chosen;
    fill(rep, rep + MAXN, 0);
    fill(sz, sz + MAXN, 1);
    fill(cnt, cnt + MAXN, 0);
    for(int i = 0; i < n; i++) {
        int s, x, y;
        cin >> s >> x;
        if(s == 1)
            y = x;
        else
            cin >> y;
        int u = find(x), v = find(y);
        if(u != v) {
            if(cnt[u] + cnt[v] != sz[u] + sz[v]) {
                join(x, y);
                chosen.push_back(i + 1);
            }
        }
        else {
            if(x == y && cnt[u] < sz[u]) {
                cnt[u]++;
                chosen.push_back(i + 1);
            }
        }
    }
    cout << p2[chosen.size()] << " " << chosen.size() << '\n';
    sort(chosen.begin(), chosen.end());
    for(auto &x : chosen)
        cout << x << " ";
    cout << '\n';
}

/*
5 4
2 1 2
2 2 3
2 3 4
2 4 1
2 1 3

*/