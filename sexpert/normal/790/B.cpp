#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
ll excess[5], answer, cnt[MAXN][5];
int sz[MAXN], h[MAXN], n, k;
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    sz[s]++;
    cnt[s][h[s] % k]++;
    for(auto v : adj[s]) {
        if(v != p) {
            h[v] = h[s] + 1;
            dfs(v, s);
            sz[s] += sz[v];
            for(int i = 0; i < k; i++)
                cnt[s][i] += cnt[v][i];
            answer += (ll)sz[v] * (n - sz[v]);
        }
    }

    // count excesses
    vector<ll> curc(5);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        for(int lh = 0; lh < k; lh++) {
            for(int rh = 0; rh < k; rh++) {
                int m = (lh + rh - 2*h[s]) % k;
                m = (m + k) % k;
                excess[m] += curc[lh] * cnt[v][rh];
            }
        }
        for(int ch = 0; ch < k; ch++) {
            int m = (ch - h[s]) % k;
            m = (m + k) % k;
            excess[m] += cnt[v][ch];
            curc[ch] += cnt[v][ch];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i < k; i++)
        answer += excess[i] * (k - i);
    cout << answer / k << '\n';
}