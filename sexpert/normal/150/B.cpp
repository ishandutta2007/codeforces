#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2005;
const ll MOD = 1e9 + 7;
int cc;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

int rep[MAXN];

int find(int u) {
    return (rep[u] == 0 ? u : rep[u] = find(rep[u]));
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return;
    cc--;
    rep[v] = u;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cc = n;
    for(int i = 1; i + k - 1 <= n; i++) {
        for(int j = 0; j < k; j++) {
            join(i + j, i + k - 1 - j);
        }
    }
    cout << mpow(m, cc) << '\n';
}