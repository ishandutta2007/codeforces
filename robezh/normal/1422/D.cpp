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
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18 + 50;

struct P {
    int x, y;
};

int n, m;
int sx, sy, fx, fy;
vi xs, ys;
P p[N];
ll dis[N];
priority_queue<pll, vector<pll>, greater<> > pque;
vector<pii> G[N];

int gxi(int x) {
    return (int)(lower_bound(all(xs), x) - xs.begin());
}

int gyi(int y) {
    return (int)(lower_bound(all(ys), y) - ys.begin());
}

int gres(int x, int y) {
    return abs(fx - x) + abs(fy - y);
}

int vis[N];
//bool good = false;



//void dfs(int x) {
//    vis[x] = 1;
//    for(auto e : G[x]) {
//        if(!vis[e.first]) dfs(e.first);
//
//    }
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;
    xs = {sx};
    ys = {sy};

    rep(i, 0, m) {
        cin >> p[i].x >> p[i].y;
        xs.push_back(p[i].x);
        ys.push_back(p[i].y);
    }
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());
    sort(all(ys));
    ys.resize(unique(all(ys)) - ys.begin());
    rep(i, 0, m) {
        int xi = gxi(p[i].x), yi = gyi(p[i].y);
        G[xi].push_back({yi + sz(xs), i});
        G[yi + sz(xs)].push_back({xi, i});
    }

    ll res = INF;
    res = abs(sx - fx) + abs(sy - fy);
    fill(dis, dis + N, INF);
    dis[gxi(sx)] = 0;
    dis[gyi(sy) + sz(xs)] = 0;
    pque.push({0, gxi(sx)});
    pque.push({0, gyi(sy) + sz(xs)});
    while(!pque.empty()) {
        auto pr = pque.top(); pque.pop();
        if(pr.first > dis[pr.second]) continue;
        assert(pr.first == dis[pr.second]);
        for(auto e : G[pr.second]) {
            if(pr.first < dis[e.first]) {
                dis[e.first] = pr.first;
                pque.push({dis[e.first], e.first});
            }
            res = min(res, pr.first + gres(p[e.second].x, p[e.second].y));
        }
        if(pr.second < sz(xs)) {
            int xi = pr.second;
            if(xi - 1 >= 0 && dis[xi] + abs(xs[xi] - xs[xi - 1]) < dis[xi - 1]) {
                dis[xi - 1] = dis[xi] + abs(xs[xi] - xs[xi - 1]);
                pque.push({dis[xi - 1], xi - 1});
            }
            if(xi + 1 < sz(xs) && dis[xi] + abs(xs[xi] - xs[xi + 1]) < dis[xi + 1]) {
                dis[xi + 1] = dis[xi] + abs(xs[xi] - xs[xi + 1]);
                pque.push({dis[xi + 1], xi + 1});
            }
        } else {
            int yi = pr.second - sz(xs);
            if(yi - 1 >= 0 && pr.first + abs(ys[yi] - ys[yi - 1]) < dis[pr.second - 1]) {
                dis[pr.second - 1] =  pr.first + abs(ys[yi] - ys[yi - 1]);
                pque.push({dis[pr.second - 1], pr.second - 1});
            }
            if(yi + 1 < sz(ys) && pr.first + abs(ys[yi] - ys[yi + 1]) < dis[pr.second + 1]) {
                dis[pr.second + 1] =  pr.first + abs(ys[yi] - ys[yi + 1]);
                pque.push({dis[pr.second + 1], pr.second + 1});
            }

        }

    }
    cout << res << '\n';
}