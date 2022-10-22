#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, l, s;

vector <ll> a;
vector <ll> h;
vector <vector <ll> > gr;
vector <ll> wsum;
vector <bool> ban;

vector <ll> last_all, last_aw;

void dfs(ll v, set <pair <ll, ll> > &all, set <pair <ll, ll> > &aw, ll &ba, ll &bw, ll &sum) {
    ba = 0, bw = 0, sum = 0;
    if (a[v] > s) {
        cout << -1;
        exit(0);
    }
    wsum[v] = 1;
    all.insert({1, v});
    last_all[v] = 1;
    aw.insert({a[v], v});
    last_aw[v] = a[v];
    for (ll u : gr[v]) {
        set <pair <ll, ll> > ap;
        set <pair <ll, ll> > pw;
        wsum[v] += wsum[u];
        ll ba1, bw1, sum1;
        dfs(u, ap, pw, ba1, bw1, sum1);
        auto it = pw.upper_bound({s - bw1 - a[v], INF});
        while (it != pw.end()) {
            ll x = it->second;
            it++;
            ap.erase({last_all[x], x});
            pw.erase({last_aw[x], x});
        }
        bw1 += a[v];
        if (ap.size() > all.size()) {
            swap(ap, all);
            swap(aw, pw);
            swap(ba, ba1);
            swap(bw, bw1);
            swap(sum, sum1);
        }
        ba += sum1;
        for (auto p : ap) {
            all.insert({p.first + ba1 - ba + sum, p.second});
            last_all[p.second] = p.first + ba1 - ba + sum;
        }
        for (auto p : pw) {
            aw.insert({p.first + bw1 - bw, p.second});
            last_aw[p.second] = p.first + bw1 - bw;
        }
        sum += sum1;
    }
    while (all.size()) {
        ll x = all.begin()->second;
        if (h[x] - h[v] + 1 > l) {
            all.erase({last_all[x], x});
            aw.erase({last_aw[x], x});
        } else {
            break;
        }
    }
    assert(all.size());
    sum = all.begin()->first + ba;
//    cout << v << "\n";
//    for (auto p : all) {
//        cout << p.first + ba << " " << p.second << "\n";
//    }
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
    cin >> n >> l >> s;
    a.resize(n);
    last_all.resize(n);
    last_aw.resize(n);
    ban.resize(n, false);
    h.resize(n, 0);
    wsum.resize(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    gr.resize(n);
    h[0] = 0;
    for (ll i = 1; i < n; i++) {
        ll p;
        cin >> p;
        p--;
        gr[p].push_back(i);
        h[i] = h[p] + 1;
    }
    set <pair <ll, ll> > all;
    set <pair <ll, ll> > aw;
    ll ba, bw, sum;
    dfs(0, all, aw, ba, bw, sum);
    cout << sum;
}