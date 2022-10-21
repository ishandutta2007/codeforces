#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e4 + 50;

struct edge {
    int to, id;
};

int col[N];
int n, m;
vector<edge> G[N];

int dep[N];
int add[N], add2[N], bedge = 0;
map<int, vi> res;

void dfs(int v, int c, int d, int eid) {
    col[v] = c;
    dep[v] = d;
    for (auto &e : G[v]) {
        if(e.id == eid) continue;
        if(col[e.to] == -1) {
            dfs(e.to, !c, d + 1, e.id);
            add[v] += add[e.to];
            add2[v] += add2[e.to];
        } else if(dep[e.to] < dep[v]) {
            if(col[e.to] == c) {
                add[e.to]--;
                add[v]++;
                bedge++;
                res[1].push_back(e.id);
            } else {
                add2[e.to]--;
                add2[v]++;
                res[0].push_back(e.id);
            }

        }
    }
    if(eid != -1) {
        if(add[v] == 0 || add2[v] == 0) res[add[v]].push_back(eid);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    memset(col, -1, sizeof(col));
    rep(i, 0, n) {
        if(col[i] == -1) {
            dfs(i, 0, 0, -1);
        }
    }
    cout << sz(res[bedge]) << '\n';
    sort(all(res[bedge]));
    for (int x : res[bedge]) cout << x + 1 << " ";
    cout << endl;
}