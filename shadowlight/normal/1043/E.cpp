#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, m;

vector <int> x, y;

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
    cin >> n >> m;
    x.resize(n);
    y.resize(n);
    map <ll, ll> xy_sumx, xy_sumy;
    map <ll, ll> xy_cntx, xy_cnty;
    ll suma = 0, sumb = 0, cnta = 0, cntb = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i]) {
            suma += y[i];
            cnta++;
        } else {
            sumb += x[i];
            cntb++;
        }
        xy_sumx[x[i] - y[i]] += x[i];
        xy_sumy[x[i] - y[i]] += y[i];
        xy_cntx[x[i] - y[i]]++;
        xy_cnty[x[i] - y[i]]++;
    }
    vector <ll> axy;
    for (auto p : xy_sumx) {
        axy.push_back(p.first);
    }
    for (ll i = 1; i < (int) axy.size(); i++) {
        ll now = axy[i], last = axy[i - 1];
        xy_sumx[now] += xy_sumx[last];
        xy_cntx[now] += xy_cntx[last];
    }
    for (ll i = (ll) axy.size() - 2; i >= 0; i--) {
        ll now = axy[i], last = axy[i + 1];
        xy_sumy[now] += xy_sumy[last];
        xy_cnty[now] += xy_cnty[last];
    }
    ll last = 0;
    vector <ll> res(n, 0);
    for (int i = 0; i < n; i++) {
        ll pos = upper_bound(axy.begin(), axy.end(), x[i] - y[i]) - axy.begin();
        if (pos != axy.size()) {
            ll d = axy[pos];
            res[i] += xy_sumy[d] + xy_cnty[d] * x[i];
        }
        ll d = x[i] - y[i];
        res[i] += xy_sumx[d] + xy_cntx[d] * y[i];
        res[i] -= x[i] + y[i];
    }
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        res[v] -= min(x[v] + y[u], x[u] + y[v]);
        res[u] -= min(x[v] + y[u], x[u] + y[v]);
    }
    for (ll i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}