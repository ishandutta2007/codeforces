#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <ll> > gr;
vector <pair <ll, ll> > points;

vector <int> used;
set <ll> qx, qy;
bool cycle = false;

void dfs(int v, int p = -1) {
    if (used[v]) {
        cycle = true;
        return;
    }
    used[v] = 1;
    qx.insert(points[v].first);
    qy.insert(points[v].second);
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
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
    ll n;
    cin >> n;
    map <ll, vector <ll> > xs, ys;
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
        xs[x].push_back(i);
        ys[y].push_back(i);
    }
    gr.resize(n);
    for (auto p : xs) {
        auto mas = p.second;
        sort(mas.begin(), mas.end());
        for (ll i = 0; i < (int) mas.size(); i++) {
            if (i) {
                gr[mas[i]].push_back(mas[i - 1]);
            }
            if (i != mas.size() - 1) {
                gr[mas[i]].push_back(mas[i + 1]);
            }
        }
    }
    for (auto p: ys) {
        auto mas = p.second;
        sort(mas.begin(), mas.end());
        for (ll i = 0; i < (int) mas.size(); i++) {
            if (i) {
                gr[mas[i]].push_back(mas[i - 1]);
            }
            if (i != mas.size() - 1) {
                gr[mas[i]].push_back(mas[i + 1]);
            }
        }
    }
    used.resize(n, 0);
    vector <ll> st(MAXN, 0);
    st[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        st[i] = st[i - 1] * 2 % INF;
    }
    ll res = 1;
    for (ll i = 0; i < n; i++) {
        if (used[i]) continue;
        cycle = false;
        qx.clear();
        qy.clear();
        dfs(i);
        ll add = st[qx.size() + qy.size()];
        if (!cycle) {
            add--;
        }
        res *= add;
        res %= INF;
    }
    cout << res;
}