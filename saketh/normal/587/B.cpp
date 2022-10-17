#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 500;
const int MOD = 1e9 + 7;

ll N, L, K;
ll val[MAXN];

vector<int> all;

int sum(int a, int b) {
    return (a + b) % MOD;
}

int prod(int a, int b) {
    return a * 1ll * b % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> L >> K;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
        all.push_back(val[i]);
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    int V = all.size();

    vector<int> apps(V);

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(all.begin(), all.end(), val[i]);
        val[i] = it - all.begin();
        apps[val[i]]++;
    }

    vector<vector<int>> ways(K+1, vector<int>(V));
    vector<vector<int>> pref(K+1, vector<int>(V));

    ways[0][0] = 1;
    for (int v = 0; v < V; v++) {
        pref[0][v] = 1;
    }

    for (int b = 1; b <= K; b++) {
        for (int v = 0; v < V; v++) {
            ways[b][v] = prod(apps[v], pref[b-1][v]);            
            pref[b][v] = ways[b][v];
            if (v > 0) pref[b][v] = sum(pref[b][v], pref[b][v-1]);
        }
    }

    ll FB = L / N;

    ll ans = 0;

    for (int l = 1; l <= K; l++) {
        ll pos = FB - l + 1;
        if (pos <= 0) continue;

        ll way = pref[l][V-1];
        ans = sum(ans, prod(pos % MOD, way));
    }

    vector<int> partial(V);
    for (int i = 0; i < L % N; i++)
        partial[val[i]]++;

    for (int l = 1; l <= K; l++) {
        if (l - 1 > FB) continue;

        for (int v = 0; v < V; v++) {
            ans = sum(ans, prod(partial[v], pref[l-1][v]));
        }
    }

    cout << ans << "\n";
}