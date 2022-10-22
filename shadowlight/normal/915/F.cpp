#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <ll> p, r, cnt;
vector <pair <ll, ll> > a;
vector <vector <int> > gr;
int n;

int get_root(int v) {
    if (p[v] == v) return v;
    return p[v] = get_root(p[v]);
}

void unite(int v, int u) {
    v = get_root(v);
    u = get_root(u);
    if (r[v] > r[u]) {
        swap(v, u);
    }
    if (r[v] == r[u]) {
        r[u]++;
    }
    cnt[u] += cnt[v];
    p[v] = u;
}

ll calc() {
    p.clear();
    r.clear();
    cnt.clear();
    p.resize(n, 0);
    r.resize(n, 0);
    cnt.resize(n, 0);
    ll sum1 = 0;
    for (int v = 0; v < n; v++) {
        p[v] = v;
        r[v] = 1;
    }
    ll sum2 = 0;
    for (int i = 0; i < n; i++) {
        int v = a[i].second;
        cnt[v] = 1;
        ll now = 0;
        ll all = 0;
        //cout << v << " " << a[i].first << "\n";
        for (int u : gr[v]) {
            //cout << get_root(u) << " " << cnt[get_root(u)] << "\n";
            all += cnt[get_root(u)];
        }
        for (int u : gr[v]) {
            if (!cnt[get_root(u)]) continue;
            now += cnt[get_root(u)] * (all - cnt[get_root(u)]);
            //cout << get_root(v) << " " << get_root(u) << "\n";
            unite(v, u);
        }
        sum1 += a[i].first * now;
        sum2 += a[i].first * all;
        //cout << i << " " << now << " " << all << "\n";
    }
    return sum1 / 2 + sum2;
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
    a.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    sort(a.begin(), a.end());
    ll max_sum = calc();
    reverse(a.begin(), a.end());
    ll min_sum = calc();
    //cout << max_sum << " " << min_sum << "\n";
    cout << max_sum - min_sum;
}