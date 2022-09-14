#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bitset>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using ld = long double;
using namespace std;

const ll N = 400001, L = 19;
vector<ll> g[N];
vector<pair<ll, ll>> ng[N];
ll tin[N], tout[N], ct, ord[N], fv[N], s[N], qq[N], h[N], up[L][N], vir[N], ft[N], k;
set<vector<ll>> qs;

void dfs(ll v, ll p) {
    ord[ct] = v;
    tin[v] = ct++;
    for (ll u : g[v]) {
        if (u == p)
            continue;
        h[u] = h[v] + 1;
        up[0][u] = v;
        dfs(u, v);
    }
    tout[v] = ct;
}

ll lca(ll u, ll v) {
    if (h[u] < h[v])
        swap(u, v);
    for (ll i = L - 1; i >= 0; i--)
        if (h[up[i][u]] >= h[v])
            u = up[i][u];
    assert(h[u] == h[v]);
    if (u == v)
        return u;
    for (ll i = L - 1; i >= 0; i--)
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    return up[0][u];
}

void add(ll v, ll ml) {
    for (auto &pp : ng[v]) {
        if (vir[pp.first] != -1)
            continue;
        if (ml >= pp.second)
            qs.insert({ft[v], pp.first, ml - pp.second});
        else {
            ll dt = (pp.second - ml + s[vir[v]] - 1) / s[vir[v]];
            qs.insert({ft[v] + dt * k, pp.first, dt * s[vir[v]] + ml - pp.second});
        }
        //qs.insert({ft[v] + (pp.second + s[vir[v]] - 1) / s[vir[v]] * k, pp.first});
    }
}

ll isp(ll u, ll v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, u, v, q, m;
    cin >> n;
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    rep(i, L - 1)
        rep(j, n)
            up[i + 1][j] = up[i][up[i][j]];
    cin >> q;
    rep(i, n)
        vir[i] = -1;
    rep(z, q) {
        cin >> k >> m;
        vector<ll> li;
        rep(i, k) {
            cin >> fv[i] >> s[i];
            fv[i]--;
            vir[fv[i]] = i;
            ft[fv[i]] = i;
            li.push_back(tin[fv[i]]);
        }
        rep(i, m) {
            cin >> qq[i];
            qq[i]--;
            li.push_back(tin[qq[i]]);
        }
        sort(all(li));
        li.resize(unique(all(li)) - li.begin());
        ll cs = li.size();
        rep(i, cs) {
            v = ord[li[i]];
            ll l1 = lca(v, ord[li[(i + 1) % cs]]);
            li.push_back(tin[l1]);
        }
        sort(all(li));
        li.resize(unique(all(li)) - li.begin());
        vector<ll> st;
        int cnt = 0;
        for (ll i : li) {
            while (!st.empty() && !isp(ord[st.back()], ord[i]))
                st.pop_back();
            if (!st.empty()) {
                v = ord[i];
                u = ord[st.back()];
                ng[v].push_back({u, h[v] - h[u]});
                ng[u].push_back({v, h[v] - h[u]});
                cnt++;
                //cout << u << ' ' << v << ' ' << h[v] - h[u] << '\n';
            }
            st.push_back(i);
        }
        assert(cnt + 1 == li.size());
        rep(i, k)
            add(fv[i], 0);
        while (!qs.empty()) {
            ll ct = (*qs.begin())[0], cv = (*qs.begin())[1], cl = (*qs.begin())[2];
            qs.erase(qs.begin());
            if (vir[cv] != -1)
                continue;
            //cout << cv << ' ' << ct % k << "!\n";
            vir[cv] = ct % k;
            ft[cv] = ct;
            add(cv, cl);
        }
        rep(i, m)
            cout << vir[qq[i]] + 1 << ' ';
        cout << '\n';
        for (ll i : li) {
            v = ord[i];
            ng[v].clear();
            vir[v] = -1;
            ft[v] = 0;
        }
    }
}