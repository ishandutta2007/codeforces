#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

vector <ll> a;
vector <vector <int> > gr;
vector <ll> sum, he;

ll all = 0;

void dfs(ll v, ll p, ll h) {
    sum[v] = a[v];
    he[v] = h;
    for (ll u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1);
        sum[v] += sum[u];
    }
}

ll maxk;

void calc(ll v, ll p, ll now) {
    maxk = max(maxk, now);
    for (ll u : gr[v]) {
        if (u == p) continue;
        calc(u, v, now + all - 2 * sum[u]);
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
    a.resize(n);
    gr.resize(n);
    sum.resize(n);
    he.resize(n);
    for (int i  = 0; i < n; i++) {
        cin >> a[i];
        all += a[i];
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0, -1, 0);
    ll st_sum = 0;
    for (ll i = 0; i < n; i++) {
        st_sum += he[i] * a[i];
    }
    maxk = st_sum;
    calc(0, -1, st_sum);
    cout << maxk;
}