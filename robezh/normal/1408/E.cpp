#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)4e5 + 50;

struct edge{
    int u, v, cost;
};

int m, n;
int a[N], b[N];
int f[N];
vector<edge> es;

int find(int i) {return f[i] == i ? i : f[i] = find(f[i]);}
void unite(int i, int j) {
    f[find(i)] = find(j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    rep(i, 0, m) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    ll totsum = 0;
    rep(i, 0, N) f[i] = i;
    rep(i, 0, m) {
        int k; cin >> k;
        rep(j, 0, k) {
            int x; cin >> x; x--;
            es.push_back({i + n, x, a[i] + b[x]});
            totsum += a[i] + b[x];
        }
    }
    sort(all(es), [](const edge &e1, const edge &e2) {
       return e1.cost > e2.cost;
    });
    for(auto &e : es) {
        if(find(e.u) != find(e.v)) {
            totsum -= e.cost;
            unite(e.u, e.v);
        }
    }
    cout << totsum << endl;
}