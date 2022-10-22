#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e8 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

vector <ll> getw, stw;

void init() {
    ll now = 0, sum = 0;
    ll cnt = 0;
    while (now < INF) {
        cnt++;
        getw.push_back(now * cnt - sum);
        stw.push_back(now);
        now += cnt;
        sum += now;
    }

}

ll get_sum(ll w) {
    /*ll l = 0, r = (int) getw.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (stw[mid] > w) {
            r = mid;
        } else {
            l = mid;
        }
    }*/
    ll l = sqrt(2 * w);
    while (l + 1 < stw.size() && stw[l + 1] <= w) {
        l++;
    }
    while (stw[l] > w) {
        l--;
    }
    //assert(stw[l] == l * (l + 1) / 2);
    return (l + 1) * (w - stw[l]) + getw[l];
}

int n, m;

vector <vector <pair <int, ll> > > gr, nr_gr;
vector <vector <int> > rev_gr;

vector <int> a;
vector <bool> used, exist;

void dfs(int v) {
    if (used[v]) {
        return;
    }
    exist[v] = 1;
    used[v] = 1;
    for (auto e : gr[v]) {
        dfs(e.first);
    }
    a.push_back(v);
}
vector <int> comp;
vector <ll> comp_sum;

int cnt = 0;

void dfs1(int v) {
    if (!exist[v] || used[v]) {
        return;
    }
    used[v] = 1;
    comp[v] = cnt;
    for (auto e : rev_gr[v]) {
        dfs1(e);
    }
}

vector <ll> dp;

ll find_ans(int v) {
    if (dp[v] != -1) {
        return dp[v];
    }
    dp[v] = comp_sum[v];
    for (auto e : nr_gr[v]) {
        dp[v] = max(dp[v], find_ans(e.first) + e.second + comp_sum[v]);
    }
    return dp[v];
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    //kek
    init();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rev_gr.resize(n);
    used.resize(n, 0);
    gr.resize(n);
    comp.resize(n, -1);
    exist.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int v, u;
        ll w;
        cin >> v >> u >> w;
        v--, u--;
        gr[v].push_back({u, w});
        rev_gr[u].push_back(v);
    }
    int s;
    cin >> s;
    s--;
    dfs(s);
    reverse(a.begin(), a.end());
    used.clear();
    used.resize(n, 0);
    for (int v : a) {
        //cout << v << " ";
        if (used[v]) continue;
        dfs1(v);
        cnt++;
    }
    nr_gr.resize(cnt);
    comp_sum.resize(cnt, 0);
    for (int v = 0; v < n; v++) {
        if (comp[v] == -1) continue;
        for (auto p : gr[v]) {
            int u = p.first, w = p.second;
            if (comp[v] == comp[u]) {
                comp_sum[comp[v]] += get_sum(w);
            } else {
                nr_gr[comp[u]].push_back({comp[v], w});
            }
        }
    }
    n = cnt;
    dp.resize(n, -1);
    ll ans = 0;
    for (int v = 0; v < n; v++) {
        ans = max(ans, find_ans(v));
    }
    cout << ans;
}