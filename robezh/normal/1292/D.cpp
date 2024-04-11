#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int N = (int)1e6 + 50, M = 5003, S = (int)4e6;
const ll INF = (ll)1e18;

struct edge {
    int to, cost;
};

int p[N];
vi pms;
vpii pds[M];
int n;
int cnts[N];
int wei[S];
int ncnt = 0;
int root;
ll sub[N], subsum[N];
map<int, edge> G[S];

void add(int v) {
    int cur = root;
    for(int i = 0; i < pds[v].size(); i++) {
        int val = pds[v][i].first, len = pds[v][i].second;
        while(len) {
            auto &e = G[cur][val];
            if(e.to == 0) {
                int nxt = ncnt++;
                e = {nxt, len};
//                cout << "adding " << cur << " " << nxt << " " << val << " " << len << endl;
                len = 0;
                cur = nxt;
            } else {
                len -= e.cost;
                cur = e.to;
            }
        }
    }
    wei[cur] = cnts[v];
//    cout << cur << " " << cnts[v] << endl;
}

void dfs(int v) {
    sub[v] = wei[v];
    for(auto &p : G[v]) {
        auto &e = p.second;
        dfs(e.to);
        sub[v] += sub[e.to];
        subsum[v] += subsum[e.to] + sub[e.to] * e.cost;
    }
}

ll res = INF;

void reroot(int v, ll psub, ll psubsum) {
    res = min(res, subsum[v] + psubsum);
//    cout << v << " " << subsum[v] + psubsum << endl;
    for(auto &p : G[v]) {
        auto &e = p.second;
        ll exsub = psub + sub[v] - sub[e.to], exsubsum = psubsum + subsum[v] - (subsum[e.to] + sub[e.to] * e.cost);
        reroot(e.to, exsub, exsubsum + exsub * e.cost);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(p, p + M, 1);
    rep(i, 2, M) {
        if (!p[i]) continue;
        pms.push_back(i);
        for (int j = 2 * i; j < M; j += i) p[j] = 0;
    }
    rep(i, 1, M) {
        for (int px : pms) {
            if(px > i) break;
            int cur = i, tot = 0;
            while(cur) tot += cur / px, cur /= px;
            pds[i].push_back({px, tot});
        }
        reverse(all(pds[i]));
    }
    cin >> n;
    rep(i, 0, n) {
        int x; cin >> x; cnts[max(1, x)]++;
    }
    root = ncnt++;
    rep(i, 1, M) {
        if(cnts[i]) add(i);
    }
    dfs(0);
    reroot(root, 0, 0);
    cout << res << '\n';





}