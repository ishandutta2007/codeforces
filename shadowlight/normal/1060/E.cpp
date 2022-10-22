#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <ll> > gr;

vector <ll> odd, even, cnto, cnte;

void dfs(ll v, ll p) {
    cnto[v] = 0;
    cnte[v] = 1;
    even[v] = 0;
    odd[v] = 0;
    for (ll u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
        even[v] += odd[u] + cnto[u];
        cnte[v] += cnto[u];
        odd[v] += even[u] + cnte[u];
        cnto[v] += cnte[u];
    }
    //cout << v << " " << cnto[v] << " " << cnte[v] << " " << even[v] << " " << odd[v] << "\n";
}

ll res = 0;

void dfs1(ll v, ll p, ll ot, ll et, ll om, ll em) {
    res += (ot + om) / 2 + em / 2;
    res += (odd[v] + cnto[v]) / 2 + even[v] / 2;
    for (ll u : gr[v]) {
        if (u == p) continue;
        ll ot1 = et + cnte[v] - 1 - cnto[u];
        ll et1 = ot + cnto[v] - cnte[u];
        ll om1 = ot1 + em + even[v] - (odd[u] + cnto[u]);
        ll em1 = et1 + om + odd[v] - (even[u] + cnte[u]);
        //cout << u << " " << ot1 << " " << et1 + 1 << " " << om1 << " " << em1 << "\n";
        dfs1(u, v, ot1, et1 + 1, om1, em1);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    gr.resize(n);
    odd.resize(n);
    even.resize(n);
    cnto.resize(n);
    cnte.resize(n, 0);
    for (int i = 1; i < n; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0, -1);
    dfs1(0, -1, 0, 1, 0, 0);
    cout << res / 2;
}