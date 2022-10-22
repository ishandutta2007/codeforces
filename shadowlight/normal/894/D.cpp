#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e5 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;

struct Query {
    ll h;
    ll tp;
    ll id;
};

vector <vector <Query> > data;
vector <ll> edges;
vector <ll> ans;

ll n, q;


vector <ll> merge(vector <ll> a, vector <ll> b) {
    vector <ll> c;
    ll an = a.size(), bn = b.size();
    ll i = 0, j = 0;
    while (i != an && j != bn) {
        if (a[i] > b[j]) {
            c.push_back(b[j]);
            j++;
        } else {
            c.push_back(a[i]);
            i++;
        }
    }
    while (i != an) {
        c.push_back(a[i]);
        i++;
    }
    while (j != bn) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

ll find_cnt(vector <ll> &a, ll x) {
    ll l = -1, r = a.size();
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (a[mid] > x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l + 1;
}

void dfs(ll v, vector <ll> &all, vector <ll> &pref) {
    if (v > n) {
        pref = {0};
        return;
    }
    all = {0};
    pref = {0, 0};
    vector <ll> left, right, prefl, prefr;
    dfs(2 * v, left, prefl);
    dfs(2 * v + 1, right, prefr);
    for (auto Q : data[v]) {
        ll h = Q.h, tp = Q.tp, id = Q.id;
        ll sum = max(h, 0LL);
        if (tp != 0 && 2 * v <= n) {
            h -= edges[2 * v];
            ll cnt = find_cnt(left, h);
            sum += cnt * h - prefl[cnt];
            h += edges[2 * v];
        }
        if (tp != 1 && 2 * v + 1 <= n) {
            h -= edges[2 * v + 1];
            ll cnt = find_cnt(right, h);
            sum += cnt * h - prefr[cnt];
            h += edges[2 * v + 1];
        }
        ans[id] += sum;
        if (v % 2) {
            Q.tp = 1;
        } else {
            Q.tp = 0;
        }
        Q.h -= edges[v];
        data[v / 2].push_back(Q);
    }
    if (left.size()) {
        for (ll &x : left) {
            x += edges[2 * v];
        }
    }
    if (right.size()) {
        for (ll &x : right) {
            x += edges[2 * v + 1];
        }
    }
    auto c = merge(left, right);
    for (ll x : c) {
        all.push_back(x);
        pref.push_back(pref.back() + x);
    }
//    cout << v << "\n";
//    for (int x : all) {
//        cout << x << " ";
//    }
//    cout << "\n";
//    for (int x : pref) {
//        cout << x << " ";
//    }
//    cout << "\n";
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n >> q;
    data.resize(n + 1);
    ans.resize(q, 0);
    edges = {0, 0};
    for (ll i = 1; i < n; i++) {
        ll x;
        cin >> x;
        edges.push_back(x);
    }
    for (ll i = 0; i < q; i++) {
        ll v, h;
        cin >> v >> h;
        data[v].push_back({h, -1, i});
    }
    vector <ll> all, pref;
    dfs(1, all, pref);
    for (ll i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}