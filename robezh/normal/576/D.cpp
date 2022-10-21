#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 155;
typedef bitset<N> bs;
const int INF = (int)1e9 + (int)1e6;

bs tmp[N];

struct edge {
    int to, lim, fwd;
};

int n, m;
vector<edge> G[N];
vi ds;
int dis[N];

struct Mat {
    bs b[N];

    Mat mul(Mat &r) {
        rep(i, 0, n) rep(j, 0, n) tmp[i][j] = r.b[j][i];
        Mat res;
        rep(i, 0, n) rep(j, 0, n) res.b[i][j] = (b[i] & tmp[j]).count() > 0;
        return res;
    }

};

Mat build_mat(int lim) {
    Mat res;
    rep(i, 0, n) {
//        res.b[i][i] = 1;
        for(auto &e : G[i]) if(e.fwd && e.lim <= lim) res.b[i][e.to] = 1;
    }
    return res;
}


Mat fastpow(Mat &p, int k) {
    Mat res;
    rep(i, 0, n) res.b[i][i] = 1;
    while(k) {
        if(k % 2) res = res.mul(p);
        k /= 2;
        p = p.mul(p);
    }
    return res;
}

void bfs(int lim) {
    fill(dis, dis + n, INF);
    dis[n - 1] = 0;
    queue<int> que;
    que.push(n - 1);
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(auto &e : G[cur]) {
            if(e.lim <= lim && dis[e.to] == INF && !e.fwd) {
                dis[e.to] = dis[cur] + 1;
                que.push(e.to);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, d; cin >> a >> b >> d; a--, b--;
        G[a].push_back({b, d, 1});
        G[b].push_back({a, d, 0});
        ds.push_back(d);
    }
    ds.push_back(0);
    sort(all(ds));
    ds.resize(unique(all(ds)) - ds.begin());

    bfs(0);
    int res = dis[0];



//    cout << res << endl;
    Mat cur;
    rep(i, 0, n) cur.b[i][i] = 1;
    rep(i, 1, sz(ds)) {
        int p = ds[i] - ds[i - 1];
        Mat mt = build_mat(ds[i - 1]);
        mt = fastpow(mt, p);
        cur = cur.mul(mt);
//        cout << i << endl;
//        rep(v, 0, n) {
//            rep(v2, 0, n) cout << cur.b[v][v2] << " ";
//            cout << endl;
//        }
        bfs(ds[i]);
        rep(v, 0, n) {
            if(cur.b[0][v]) res = min(res, ds[i] + dis[v]);
        }
    }
    if(res == INF) cout << "Impossible\n";
    else cout << res << '\n';





}