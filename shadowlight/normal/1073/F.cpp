#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;
int n;

struct State {
    int cnt, sum, v1, v2, u1, u2;
};

ostream &operator<<(ostream &out, State a) {
    out << a.cnt << " " << a.sum << " " << a.v1 << " " << a.v2 << " " << a.u1 << " " << a.u2;
    return out;
}

vector <State> dp1, dp2;

vector <pair <int, int> > mp, mp2, top;
vector <int> tox1, tox2;

bool operator<(State a, State b) {
    if (a.cnt != b.cnt) {
        return a.cnt < b.cnt;
    }
    if (a.sum != b.sum) {
        return a.sum < b.sum;
    }
    return false;
}

bool operator==(State a, State b) {
    return a.cnt == b.cnt && a.sum == b.sum;
}

bool operator>(State a, State b) {
    return b < a;
}

void calc_mp(int v, int p) {
    pair <int, int> h1 = {-1, -1}, h2 = {-1, -1}, h3 = {-1, -1};
    int to1 = -1, to2 = -1, to3 = -1;
    for (int u : gr[v]) {
        if (u == p) continue;
        calc_mp(u, v);
        auto hupd = mp[u];
        hupd.first++;
        if (hupd.first >= h1.first) {
            h3 = h2;
            to3 = to2;
            h2 = h1;
            to2 = to1;
            h1 = hupd;
            to1 = u;
        } else if (hupd.first >= h2.first) {
            h3 = h2;
            to3 = to2;
            h2 = hupd;
            to2 = u;
        } else if (hupd.first >= h3.first) {
            h3 = hupd;
            to3 = u;
        }
    }
    if (h1.first == -1) {
        mp[v] = {0, v};
        tox1[v] = -1;
    } else {
        mp[v] = h1;
        tox1[v] = to1;
    }
    if (h2.first == -1) {
        mp2[v] = {0, v};
        tox2[v] = -1;
    } else {
        mp2[v] = h2;
        tox2[v] = to2;
    }
}

void dfs(int v, int p) {
    //cout << v << " " << tox1[v] << " " << tox2[v] << " " << top[v].first << " " << top[v].second << "\n";
    dp1[v] = {-1};
    dp2[v] = {-1};
    pair <int, int> h1 = {-1, -1}, h2 = {-1, -1}, h3 = {-1, -1};
    int to1 = -1, to2 = -1, to3 = -1;
    State dp2a = {-1}, dp2b = {-1};
    for (int u : gr[v]) {
        if (u == p) continue;
        top[u] = {0, u};
        top[u] = max(top[u], {top[v].first + 1, top[v].second});
        if (tox1[v] != u) {
            top[u] = max(top[u], {mp[v].first + 1, mp[v].second});
        } else {
            top[u] = max(top[u], {mp2[v].first + 1, mp2[v].second});
        }
        dfs(u, v);
        auto hupd = mp[u];
        hupd.first++;
        if (hupd.first >= h1.first) {
            h3 = h2;
            to3 = to2;
            h2 = h1;
            to2 = to1;
            h1 = hupd;
            to1 = u;
        } else if (hupd.first >= h2.first) {
            h3 = h2;
            to3 = to2;
            h2 = hupd;
            to2 = u;
        } else if (hupd.first >= h3.first) {
            h3 = hupd;
            to3 = u;
        }
        auto dp1_upd = dp1[u];
        if (dp1_upd.cnt != -1) {
            dp1_upd.cnt++;
            dp1[v] = max(dp1[v], dp1_upd);
        }
        dp2[v] = max(dp2[v], dp2[u]);
        if (dp1[u] > dp2a || dp1[u] == dp2a) {
            dp2b = dp2a;
            dp2a = dp1[u];
        } else if (dp1[u] > dp2b) {
            dp2b = dp1[u];
        }
    }
    if (h2.first != -1) {
        dp1[v] = max(dp1[v], {0, h1.first + h2.first, h1.second, h2.second, -1, -1});
    }
    if (dp2b.cnt != -1) {
        dp2[v] = max(dp2[v], {dp2a.cnt + dp2b.cnt + 2, dp2a.sum + dp2b.sum, dp2a.v1, dp2a.v2, dp2b.v1, dp2b.v2});
    }
    if (p != -1) {
        auto hupd = top[v];
        if (hupd.first >= h1.first) {
            h3 = h2;
            to3 = to2;
            h2 = h1;
            to2 = to1;
            h1 = hupd;
            to1 = p;
        } else if (hupd.first >= h2.first) {
            h3 = h2;
            to3 = to2;
            h2 = hupd;
            to2 = p;
        } else if (hupd.first >= h3.first) {
            h3 = hupd;
            to3 = p;
        }
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        if (dp1[u].cnt == -1) continue;
        if (h2.first == -1) continue;
        auto d = dp1[u];
        if (to1 == u) {
            if (h3.first != -1) {
                dp2[v] = max(dp2[v], {d.cnt + 1, d.sum + h2.first + h3.first, d.v1, d.v2, h2.second, h3.second});
            }
        } else if (to2 == u) {
            if (h3.first != -1) {
                dp2[v] = max(dp2[v], {d.cnt + 1, d.sum + h1.first + h3.first, d.v1, d.v2, h1.second, h3.second});
            }
        } else {
            dp2[v] = max(dp2[v], {d.cnt + 1, d.sum + h1.first + h2.first, d.v1, d.v2, h1.second, h2.second});
        }
    }
//    cout << v << "\n";
//    cout << mp[v].first << " " << mp[v].second << "\n";
//    cout << dp1[v] << "\n" << dp2[v] << "\n";
//    cout << dp2a << "\n" << dp2b << "\n";
    //cout << h1.first << " " << h1.second << " " << h2.first << " " << h2.second << "\n";
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
    cin >> n;
    gr.resize(n);
    dp1.resize(n);
    dp2.resize(n);
    mp.resize(n);
    mp2.resize(n);
    top.resize(n);
    tox1.resize(n);
    tox2.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    top[0] = {0, 0};
    calc_mp(0, -1);
    dfs(0, -1);
    cout << dp2[0].v1 + 1 << " " << dp2[0].u1 + 1 << "\n" << dp2[0].v2 + 1 << " " << dp2[0].u2 + 1 << "\n";
}