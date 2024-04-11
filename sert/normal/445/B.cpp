#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e6 + 34;

typedef long long ll;

ll n, m, v1, v2, sz, ans;
vector <ll> es[N];
bool u[N];

void dfs(ll v) {
    if (u[v]) return;
    u[v] = true;
    for (int i = 0; i < es[v].size(); i++)
        dfs(es[v][i]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    for (int i = 0; i < n; i++)
        if (!u[i]) {
            sz++;
            dfs(i);
            ans = max(ans, sz);
        }
    ans = n - sz;
    cout << (1ll << ans);
    return 0;
}