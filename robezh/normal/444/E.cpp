#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 3005;

int f[N], sum[N], cnt[N];

int find(int i) {return f[i] == i ? i : f[i] = find(f[i]);}
void unite(int u, int v) {
    u = find(u), v = find(v);
    f[u] = v;
    sum[v] += sum[u];
    cnt[v] += cnt[u];
}


struct eg {
    int a, b, cost;
};


int n, m;
int a[N];
vector<eg> es;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        es.push_back({a, b, c});
    }
    sort(all(es), [](const eg &e1, const eg &e2) {
        return e1.cost < e2.cost;
    });
    ll tsum = 0;
    rep(i, 0, n) cin >> a[i], tsum += a[i], sum[i] = a[i];
    iota(f, f + n, 0);
    fill(cnt, cnt + n, 1);
    int res = 0;
    for (auto &e : es) {
        unite(e.a, e.b);
//        cout << e.a << " " << e.b << " " << cnt[find(e.a)] << " " << sum[find(e.a)] << endl;
        res = e.cost;
        if(cnt[find(e.a)] > tsum - sum[find(e.a)]) break;
    }
    cout << res << '\n';
}